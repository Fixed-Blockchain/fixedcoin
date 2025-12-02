# FixedCoin Core 26.0.0 - MANDATORY UPDATE

This is a **mandatory security update** for all users, node operators, miners, and exchanges. This release contains a planned hard-forking consensus change that will activate at a future block height.

**All users MUST upgrade before block height 628 to remain on the correct network.**

## What's New in This Release

###  Consensus Rule Adjustment (Hard Fork)

This release includes a critical, one-time consensus rule change that activates at block `628`. This rule is designed to invalidate a specific problematic transaction history to protect the integrity of the blockchain.

# **WARNING:** Failure to upgrade your node before this block height will cause your node to follow an incorrect chain. This is a mandatory, time-sensitive update.

###  Network Security & Stability Enhancements

To further secure the network against future attacks and improve sync times for new nodes, this release includes:

* **New Checkpoints:** Added new validated checkpoints to the chain history, strengthening the immutability of the blockchain.
* **Minimum Chain Work (`minchainwork`):** Implemented a `minchainwork` value to ensure that nodes follow the chain with the most cumulative proof-of-work, protecting against certain types of consensus attacks.
* **P2P Protocol Version:** The protocol version has been increased to `70017`. This helps new nodes identify peers who have successfully applied this critical update.

## How to Upgrade

1.  Shut down your existing FixedCoin Core wallet or daemon.
2.  Download and install the new 26.0.0 binaries for your operating system.
3.  Restart your wallet or daemon.

Your node will be ready for the upcoming hard fork.

