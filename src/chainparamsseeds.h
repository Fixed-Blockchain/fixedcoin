#ifndef FIXEDCOIN_CHAINPARAMSSEEDS_H
#define FIXEDCOIN_CHAINPARAMSSEEDS_H
/**
 * List of fixed seed nodes for the fixedcoin network
 *
 * Each line contains a BIP155 serialized (networkID, addr, port) tuple.
 * Format: 0x01 (IPv4) 0x04 (4 bytes) [IP bytes] [port bytes big-endian]
 */
static const uint8_t chainparams_seed_main[] = {
    // node1.fixedcoin.org - 87.106.216.17:24768 (0x60c0)
    0x01, 0x04, 0x57, 0x6a, 0xd8, 0x11, 0x60, 0xc0,
    
    // node2.fixedcoin.org - 217.160.149.211:24768 (0x60c0)
    0x01, 0x04, 0xd9, 0xa0, 0x95, 0xd3, 0x60, 0xc0,
};

static const uint8_t chainparams_seed_test[] = {
    // Add testnet seed nodes here when available
    // Add testnet seed nodes here when available
};

static const uint8_t chainparams_seed_testnet4[] = {
    // Add testnet4 seed nodes here when available
};

static const uint8_t chainparams_seed_signet[] = {
    // Add signet seed nodes here when available
};

static const uint8_t chainparams_seed_regtest[] = {
    // Regtest typically doesn't need seed nodes
};

#endif // FIXEDCOIN_CHAINPARAMSSEEDS_H
