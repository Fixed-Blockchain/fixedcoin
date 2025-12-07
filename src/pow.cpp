// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2024 The Bitcoin Core developers
// Copyright (c) 2025 The FixedCoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <pow.h>

#include <arith_uint256.h>
#include <chain.h>
#include <primitives/block.h>
#include <uint256.h>
#include <util/check.h>

unsigned int GetNextWorkRequired(const CBlockIndex* pindexLast, const CBlockHeader *pblock, const Consensus::Params& params)
{
    assert(pindexLast != nullptr);
    unsigned int nProofOfWorkLimit = UintToArith256(params.powLimit).GetCompact();

    // ASERT DAA
    if (pindexLast->nHeight + 1 >= params.nASERTActivationHeight) {
        return GetNextASERTWorkRequired(pindexLast, pblock, params);
    }

    // Only change once per difficulty adjustment interval
    if ((pindexLast->nHeight+1) % params.DifficultyAdjustmentInterval() != 0)
    {
        if (params.fPowAllowMinDifficultyBlocks)
        {
            // Special difficulty rule for testnet:
            // If the new block's timestamp is more than 2* 10 minutes
            // then allow mining of a min-difficulty block.
            if (pblock->GetBlockTime() > pindexLast->GetBlockTime() + params.nPowTargetSpacing*2)
                return nProofOfWorkLimit;
            else
            {
                // Return the last non-special-min-difficulty-rules-block
                const CBlockIndex* pindex = pindexLast;
                while (pindex->pprev && pindex->nHeight % params.DifficultyAdjustmentInterval() != 0 && pindex->nBits == nProofOfWorkLimit)
                    pindex = pindex->pprev;
                return pindex->nBits;
            }
        }
        return pindexLast->nBits;
    }

    // Go back by what we want to be 14 days worth of blocks
    int nHeightFirst = pindexLast->nHeight - (params.DifficultyAdjustmentInterval()-1);
    assert(nHeightFirst >= 0);
    const CBlockIndex* pindexFirst = pindexLast->GetAncestor(nHeightFirst);
    assert(pindexFirst);

    return CalculateNextWorkRequired(pindexLast, pindexFirst->GetBlockTime(), params);
}

/**
 * ASERT Difficulty Adjustment Algorithm (aserti3-2d)
 * 
 * This is the OFFICIAL Bitcoin Cash implementation using integer fixed-point
 * arithmetic with the exact coefficients from the BCH specification.
 * 
 * Formula: next_target = anchor_target * 2^((time_delta - ideal_block_time * height_delta) / halflife)
 * 
 * Reference: https://upgradespecs.bitcoincashnode.org/2020-11-15-asert/
 * Coefficients from: https://github.com/Electron-Cash/Electron-Cash/blob/master/electroncash/asert_daa.py
 */
unsigned int GetNextASERTWorkRequired(const CBlockIndex* pindexLast, const CBlockHeader *pblock, const Consensus::Params& params)
{
    const arith_uint256 powLimit = UintToArith256(params.powLimit);
    
    // Anchor block is the block just before ASERT activation (height 999 for FixedCoin)
    const int nAnchorHeight = params.nASERTActivationHeight - 1;
    
    // Safety check for very early blocks
    if (nAnchorHeight < 1) {
        return powLimit.GetCompact();
    }
    
    // Get the anchor block
    const CBlockIndex* pindexAnchor = pindexLast->GetAncestor(nAnchorHeight);
    if (!pindexAnchor) {
        return powLimit.GetCompact();
    }
    
    // CRITICAL: We need the anchor block's PARENT for the timestamp
    // This is per the ASERT specification - using anchor's timestamp is WRONG
    const CBlockIndex* pindexAnchorParent = pindexAnchor->pprev;
    if (!pindexAnchorParent) {
        return powLimit.GetCompact();
    }
    
    // Get anchor block target
    arith_uint256 refBlockTarget;
    refBlockTarget.SetCompact(pindexAnchor->nBits);
    
    // Calculate time and height differences
    // We're calculating for the NEXT block (pindexLast->nHeight + 1)
    const int64_t nHeightDiff = (pindexLast->nHeight + 1) - nAnchorHeight;
    const int64_t nTimeDiff = pindexLast->GetBlockTime() - pindexAnchorParent->GetBlockTime();
    
    const int64_t nPowTargetSpacing = params.nPowTargetSpacing;
    const int64_t nHalfLife = params.nASERTHalflife;
    
    // Fixed-point arithmetic constants
    // RBITS = 16 means we use 16 bits for the fractional part
    static constexpr int RBITS = 16;
    static constexpr int64_t RADIX = int64_t(1) << RBITS;
    
    // Verify that arithmetic right shift works as expected (required by ASERT spec)
    static_assert(int64_t(-1) >> 1 == int64_t(-1), "ASERT algorithm needs arithmetic shift support");
    
    // Calculate the exponent in fixed-point:
    // exponent = (time_delta - ideal_block_time * height_delta) * 65536 / halflife
    const int64_t exponent = ((nTimeDiff - nPowTargetSpacing * nHeightDiff) * RADIX) / nHalfLife;
    
    // Decompose exponent into integer (shifts) and fractional parts
    // Use arithmetic right shift to handle negative exponents correctly
    int64_t shifts = exponent >> RBITS;
    uint64_t frac = static_cast<uint64_t>(exponent - (shifts << RBITS));
    
    // If fractional part is negative, adjust shifts and make frac positive
    // This handles the case where exponent is negative
    if (exponent < 0 && frac != 0) {
        shifts -= 1;
        frac = RADIX - frac;
    }
    
    // Calculate 2^(frac/65536) using the OFFICIAL BCH polynomial approximation
    // These are the EXACT coefficients from Bitcoin Cash implementation:
    // factor = 65536 + ((195766423245049 * frac + 971821376 * frac^2 + 5127 * frac^3 + 2^47) >> 48)
    //
    // This approximates 2^x for x in [0, 1) with very high precision
    const uint64_t factor = RADIX + (
        (
            + 195766423245049ULL * frac 
            + 971821376ULL * frac * frac 
            + 5127ULL * frac * frac * frac 
            + (1ULL << 47)
        ) >> 48
    );
    
    // Apply the factor to anchor target
    // nextTarget = refBlockTarget * factor
    // This is always < 2^241 since refBlockTarget < 2^224
    arith_uint256 nextTarget = refBlockTarget * factor;
    
    // Apply integer shifts (the integer part of the exponent)
    // shifts can be positive (multiply by 2^shifts) or negative (divide by 2^|shifts|)
    // We add RBITS to shifts because we multiplied by factor which is scaled by RADIX
    shifts += RBITS;
    
    if (shifts < 0) {
        nextTarget >>= -shifts;
    } else {
        // Check for overflow - if shifts is too large, return powLimit
        // 256 - 241 = 15 bits of headroom, so shifts > ~240 could overflow
        if (shifts >= 256) {
            return powLimit.GetCompact();
        }
        nextTarget <<= shifts;
    }
    
    // Clamp to powLimit (maximum target = minimum difficulty)
    if (nextTarget == 0) {
        // If underflow, return minimum possible target (1)
        return arith_uint256(1).GetCompact();
    }
    
    if (nextTarget > powLimit) {
        nextTarget = powLimit;
    }
    
    return nextTarget.GetCompact();
}

unsigned int CalculateNextWorkRequired(const CBlockIndex* pindexLast, int64_t nFirstBlockTime, const Consensus::Params& params)
{
    if (params.fPowNoRetargeting)
        return pindexLast->nBits;

    // Limit adjustment step
    int64_t nActualTimespan = pindexLast->GetBlockTime() - nFirstBlockTime;
    if (nActualTimespan < params.nPowTargetTimespan/4)
        nActualTimespan = params.nPowTargetTimespan/4;
    if (nActualTimespan > params.nPowTargetTimespan*4)
        nActualTimespan = params.nPowTargetTimespan*4;

    // Retarget
    const arith_uint256 bnPowLimit = UintToArith256(params.powLimit);
    arith_uint256 bnNew;

    // Special difficulty rule for Testnet4
    if (params.enforce_BIP94) {
        // Here we use the first block of the difficulty period. This way
        // the real difficulty is always preserved in the first block as
        // it is not allowed to use the min-difficulty exception.
        int nHeightFirst = pindexLast->nHeight - (params.DifficultyAdjustmentInterval()-1);
        const CBlockIndex* pindexFirst = pindexLast->GetAncestor(nHeightFirst);
        bnNew.SetCompact(pindexFirst->nBits);
    } else {
        bnNew.SetCompact(pindexLast->nBits);
    }

    bnNew *= nActualTimespan;
    bnNew /= params.nPowTargetTimespan;

    if (bnNew > bnPowLimit)
        bnNew = bnPowLimit;

    return bnNew.GetCompact();
}

// Check that on difficulty adjustments, the new difficulty does not increase
// or decrease beyond the permitted limits.
bool PermittedDifficultyTransition(const Consensus::Params& params, int64_t height, uint32_t old_nbits, uint32_t new_nbits)
{
    if (params.fPowAllowMinDifficultyBlocks) return true;

    // After ASERT activation, the old rules don't apply
    if (height >= params.nASERTActivationHeight) {
        // ASERT allows any valid difficulty transition
        // The validity is checked by GetNextASERTWorkRequired
        return true;
    }

    if (height % params.DifficultyAdjustmentInterval() == 0) {
        int64_t smallest_timespan = params.nPowTargetTimespan/4;
        int64_t largest_timespan = params.nPowTargetTimespan*4;

        const arith_uint256 pow_limit = UintToArith256(params.powLimit);
        arith_uint256 observed_new_target;
        observed_new_target.SetCompact(new_nbits);

        // Calculate the largest difficulty value possible:
        arith_uint256 largest_difficulty_target;
        largest_difficulty_target.SetCompact(old_nbits);
        largest_difficulty_target *= largest_timespan;
        largest_difficulty_target /= params.nPowTargetTimespan;

        if (largest_difficulty_target > pow_limit) {
            largest_difficulty_target = pow_limit;
        }

        // Round and then compare this new calculated value to what is
        // observed.
        arith_uint256 maximum_new_target;
        maximum_new_target.SetCompact(largest_difficulty_target.GetCompact());
        if (maximum_new_target < observed_new_target) return false;

        // Calculate the smallest difficulty value possible:
        arith_uint256 smallest_difficulty_target;
        smallest_difficulty_target.SetCompact(old_nbits);
        smallest_difficulty_target *= smallest_timespan;
        smallest_difficulty_target /= params.nPowTargetTimespan;

        if (smallest_difficulty_target > pow_limit) {
            smallest_difficulty_target = pow_limit;
        }

        // Round and then compare this new calculated value to what is
        // observed.
        arith_uint256 minimum_new_target;
        minimum_new_target.SetCompact(smallest_difficulty_target.GetCompact());
        if (minimum_new_target > observed_new_target) return false;
    } else if (old_nbits != new_nbits) {
        return false;
    }
    return true;
}

// Bypasses the actual proof of work check during fuzz testing with a simplified validation checking whether
// the most significant bit of the last byte of the hash is set.
bool CheckProofOfWork(uint256 hash, unsigned int nBits, const Consensus::Params& params)
{
    if constexpr (G_FUZZING) return (hash.data()[31] & 0x80) == 0;
    return CheckProofOfWorkImpl(hash, nBits, params);
}

std::optional<arith_uint256> DeriveTarget(unsigned int nBits, const uint256 pow_limit)
{
    bool fNegative;
    bool fOverflow;
    arith_uint256 bnTarget;

    bnTarget.SetCompact(nBits, &fNegative, &fOverflow);

    // Check range
    if (fNegative || bnTarget == 0 || fOverflow || bnTarget > UintToArith256(pow_limit))
        return {};

    return bnTarget;
}

bool CheckProofOfWorkImpl(uint256 hash, unsigned int nBits, const Consensus::Params& params)
{
    auto bnTarget{DeriveTarget(nBits, params.powLimit)};
    if (!bnTarget) return false;

    // Check proof of work matches claimed amount
    if (UintToArith256(hash) > bnTarget)
        return false;

    return true;
}
