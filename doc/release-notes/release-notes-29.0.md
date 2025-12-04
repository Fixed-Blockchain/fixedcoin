FixedCoin Core version 29.0 is now available.

This release marks a significant update to the FixedCoin codebase, bringing it in line with the latest upstream Bitcoin Core developments.

Differences from Main Branch
============================

Upstream Synchronization
------------------------
*   **Bitcoin Core v29 Base**: The codebase has been updated to be based on Bitcoin Core v29.0. This brings in numerous performance improvements, bug fixes, and new features from the upstream project.

Build System
------------
*   **CMake**: The build system has been migrated from Autotools to **CMake**. This aligns with the modern Bitcoin Core build process and improves build times and reliability.
    *   Build instructions have been updated to reflect the new `cmake` workflow.

Network Support
---------------
*   **TestNet4**: Support for **TestNet4** has been added (`CTestNet4Params`). This includes the new genesis block and network parameters for the next generation test network.

Codebase Changes
----------------
*   **Client Versioning**: Updated `src/clientversion.cpp` to use `fixedcoin-build-config.h` and `fixedcoin-build-info.h`, supporting the new CMake build system.
*   **Chain Parameters**:
    *   Added `TestNet4` parameters.
    *   Mainnet and Testnet parameters (ports, seeds, prefixes) are configured for FixedCoin.
    *   Regtest parameters have been updated (reverted to upstream defaults in some cases).

Documentation
-------------
*   Documentation files have been synchronized with the `main` branch, ensuring that the latest FixedCoin-specific instructions are available in the v29 release.
