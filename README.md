# FixedCoin 🔒

![FixedCoin Logo](https://github.com/Fixed-Blockchain/fixedcoin/blob/main/fix.png)

![Version](https://img.shields.io/badge/version-1.0.0-blue.svg)
![License](https://img.shields.io/badge/license-MIT-green.svg)
![Supply](https://img.shields.io/badge/supply-10%2C000%20FIX-orange.svg)
![Algorithm](https://img.shields.io/badge/algorithm-SHA--256-blue.svg)
![Status](https://img.shields.io/badge/status-FIXED-red.svg)

**🌐 [Website](https://fixedcoin.org) | 🔍 [Explorer](https://explorer.fixedcoin.org) | 📦 [Releases](https://github.com/Fixed-Blockchain/fixedcoin/releases)**

> **"Once mined at block 1, this repository will be archived. Everything is Fixed."**

---

## 📚 Table of Contents

- [What is FixedCoin?](#-what-is-fixedcoin)
- [Why FixedCoin?](#-why-fixedcoin)
- [Technical Specifications](#-technical-specifications)
- [Network](#-network)
- [Downloads](#-downloads)
- [Quick Start Guide](#-quick-start-guide)
- [Ubuntu Server Setup](#️-ubuntu-server-2204-node-setup)
- [Node Management Commands](#-node-management-commands)
- [Mining FixedCoin](#️-mining-fixedcoin)
- [Supply Schedule](#-supply-schedule)
- [Security Best Practices](#-security-best-practices)
- [Troubleshooting](#-troubleshooting)
- [FAQ](#-frequently-asked-questions)
- [Additional Resources](#-additional-resources)
- [Disclaimer](#️-disclaimer)
- [License](#-license)

---

## 🔐 What is FixedCoin?

FixedCoin is an ultra-rare cryptocurrency with a total supply of only **10,000 FIX**. Built on Bitcoin's proven codebase and secured by SHA-256 mining, FixedCoin represents the ultimate experiment in digital scarcity and immutability.

**The Fixed Concept:**
- **1,600 FIX premine at block 1** for initial distribution and development
- Repository will be **permanently archived** after block 1
- No future code changes or governance
- Pure, immutable, fixed forever

## 🎯 Why FixedCoin?

FixedCoin represents a radical experiment in cryptocurrency design:

- ✅ **No Governance Drama** - No debates, no forks, no community splits
- ✅ **No Protocol Upgrades** - What you see is what you get, forever
- ✅ **No Inflation Surprises** - 10,000 FIX. That's it. Forever.
- ✅ **Fair Launch with Premine** - 1,600 FIX premine (16% of supply) for ecosystem development
- ✅ **No Uncertainty** - The protocol is completely predictable
- ✅ **Ultimate Scarcity** - 2,100x rarer than Bitcoin

**The only cryptocurrency that will never change.**

## 💎 Technical Specifications

| Parameter | Value |
|-----------|-------|
| **Total Supply** | 10,000 FIX |
| **Genesis Block** | 1 FIX (Block 0) |
| **Premine Block** | 1,600 FIX (Block 1) |
| **Block Reward** | 1 FIX (initial, from block 2) |
| **Halving Interval** | 4,200 blocks |
| **Last Reward Block** | 113,400 |
| **Distribution Period** | 2 years |
| **Premine Allocation** | 16% of total supply |
| **Mining Algorithm** | SHA-256 |
| **Block Time** | 10 minutes |
| **Difficulty Adjustment** | Every 3 blocks |
| **Coinbase Maturity** | 100 blocks |
| **Transaction Confirmations** | 6 blocks |
| **Address Format** | Bech32 (fix1...) |
| **RPC Port** | 24761 |
| **P2P Port** | 24768 |

## 🌐 Network

**Official Seed Nodes:**
- node1.fixedcoin.org:24768
- node2.fixedcoin.org:24768

**ZMQ Ports:**
- Raw Block: 24763
- Raw TX: 24764
- Hash TX: 24765
- Hash Block: 24766

**Block Explorer:**
- https://explorer.fixedcoin.org

## 📥 Downloads

### Latest Release: v25.0.0

Download from [GitHub Releases](https://github.com/Fixed-Blockchain/fixedcoin/releases/tag/FIX)

#### Windows

**Setup Installer (Recommended)**
- [fixedcoin-25.0.0-win64-setup.exe](https://github.com/Fixed-Blockchain/fixedcoin/releases/download/FIX/fixedcoin-25.0.0-win64-setup.exe)
- SHA256: `2633baead034c5d6a5b036951560f5a859ca8257d8a154ce63ae3e0384009e07`

**Portable Archive**
- [fixedcoin-25.0.0-win64.zip](https://github.com/Fixed-Blockchain/fixedcoin/releases/download/FIX/fixedcoin-25.0.0-win64.zip)
- SHA256: `4ad54f7d9f509321f80d7b13fecd4f355db7aa6edc82a9c533dde358f2811f97`

#### macOS

**Disk Image (Recommended)**
- [fixedcoin-25.0.0-apple-darwin-setup.dmg](https://github.com/Fixed-Blockchain/fixedcoin/releases/download/FIX/fixedcoin-25.0.0-apple-darwin-setup.dmg)
- SHA256: `442a8409f90539d5de618ddc100249700044718c14b3cdbe394f38f870405391`

**Archive (Intel)**
- [fixedcoin-25.0.0-x86_64-apple-darwin.tar.gz](https://github.com/Fixed-Blockchain/fixedcoin/releases/download/FIX/fixedcoin-25.0.0-x86_64-apple-darwin.tar.gz)
- SHA256: `0af514ea233d8b58f069d3e0b7cfc4beb7f945e75cb6373e3457f5eb0db7c57d`

#### Linux

**x86_64 (64-bit Intel/AMD)**
- [fixedcoin-25.0.0-x86_64-linux-gnu.tar.gz](https://github.com/Fixed-Blockchain/fixedcoin/releases/download/FIX/fixedcoin-25.0.0-x86_64-linux-gnu.tar.gz)
- SHA256: `487afa3538250a27fda83bfd847eb9d0c21ca59b6ff0d09972c6dbd155405ca8`

**ARM64 (Raspberry Pi, ARM servers)**
- [fixedcoin-25.0.0-aarch64-linux-gnu.tar.gz](https://github.com/Fixed-Blockchain/fixedcoin/releases/download/FIX/fixedcoin-25.0.0-aarch64-linux-gnu.tar.gz)
- SHA256: `9b71643e5d3195800148c8e8aac38577ff445258959b880d86b3cdd53898801e`

#### Source Code

- [Source code (zip)](https://github.com/Fixed-Blockchain/fixedcoin/archive/refs/tags/FIX.zip)
- [Source code (tar.gz)](https://github.com/Fixed-Blockchain/fixedcoin/archive/refs/tags/FIX.tar.gz)

## 🚀 Quick Start Guide

### Windows Installation

**Using Installer (Recommended):**
1. Download [fixedcoin-25.0.0-win64-setup.exe](https://github.com/Fixed-Blockchain/fixedcoin/releases/download/FIX/fixedcoin-25.0.0-win64-setup.exe)
2. Run the installer and follow the setup wizard
3. Launch FixedCoin from Start Menu
4. Wait for blockchain synchronization

**Using Portable Archive:**
1. Download [fixedcoin-25.0.0-win64.zip](https://github.com/Fixed-Blockchain/fixedcoin/releases/download/FIX/fixedcoin-25.0.0-win64.zip)
2. Extract the archive to a folder (e.g., `C:\FixedCoin`)
3. Run `fixedcoin-qt.exe` to start the wallet
4. Wait for blockchain synchronization

### macOS Installation

**Using Disk Image (Recommended):**
1. Download [fixedcoin-25.0.0-apple-darwin-setup.dmg](https://github.com/Fixed-Blockchain/fixedcoin/releases/download/FIX/fixedcoin-25.0.0-apple-darwin-setup.dmg)
2. Open the DMG file
3. Drag FixedCoin to Applications folder
4. Launch FixedCoin from Applications
5. Wait for blockchain synchronization

**Using Archive:**
```bash
# Download
curl -L -O https://github.com/Fixed-Blockchain/fixedcoin/releases/download/FIX/fixedcoin-25.0.0-x86_64-apple-darwin.tar.gz

# Extract
tar -xzf fixedcoin-25.0.0-x86_64-apple-darwin.tar.gz

# Run GUI wallet
./fixedcoin-qt

# Or run daemon in background
./fixedcoind -daemon
```

### Linux Desktop Installation

**For x86_64 systems:**
```bash
# Download
wget https://github.com/Fixed-Blockchain/fixedcoin/releases/download/FIX/fixedcoin-25.0.0-x86_64-linux-gnu.tar.gz

# Extract
tar -xzf fixedcoin-25.0.0-x86_64-linux-gnu.tar.gz

# Change to bin directory
cd fixedcoin-25.0.0/bin

# Run GUI wallet
./fixedcoin-qt

# Or run daemon in background
./fixedcoind -daemon
```

**For ARM64 systems (Raspberry Pi, etc.):**
```bash
# Download
wget https://github.com/Fixed-Blockchain/fixedcoin/releases/download/FIX/fixedcoin-25.0.0-aarch64-linux-gnu.tar.gz

# Extract
tar -xzf fixedcoin-25.0.0-aarch64-linux-gnu.tar.gz

# Change to bin directory
cd fixedcoin-25.0.0/bin

# Run GUI wallet
./fixedcoin-qt

# Or run daemon in background
./fixedcoind -daemon
```

## 🖥️ Ubuntu Server 22.04 Node Setup

Complete step-by-step guide to install and run a FixedCoin node on Ubuntu Server 22.04.

### Prerequisites

```bash
sudo apt-get update && sudo apt-get upgrade -y
```

### Step 1: Create Directory Structure

```bash
# Create main directory
sudo mkdir -p /var/fixedcoin

# Create subdirectories
sudo mkdir -p /var/fixedcoin/bin
sudo mkdir -p /var/fixedcoin/data
sudo mkdir -p /var/fixedcoin/downloads

# Set ownership
sudo chown -R $USER:$USER /var/fixedcoin
```

Verify:
```bash
ls -la /var/fixedcoin
```

Expected output:
```
drwxr-xr-x bin
drwxr-xr-x data
drwxr-xr-x downloads
```

### Step 2: Download FixedCoin Binaries

```bash
cd /var/fixedcoin/downloads

# For x86_64 systems (Intel/AMD)
wget https://github.com/Fixed-Blockchain/fixedcoin/releases/download/FIX/fixedcoin-25.0.0-x86_64-linux-gnu.tar.gz

# OR for ARM64 systems (Raspberry Pi, ARM servers)
# wget https://github.com/Fixed-Blockchain/fixedcoin/releases/download/FIX/fixedcoin-25.0.0-aarch64-linux-gnu.tar.gz
```

### Step 3: Extract Files

**For x86_64:**
```bash
tar -xzf fixedcoin-25.0.0-x86_64-linux-gnu.tar.gz
```

**For ARM64:**
```bash
tar -xzf fixedcoin-25.0.0-aarch64-linux-gnu.tar.gz
```

Verify extraction:
```bash
cd fixedcoin-25.0.0/bin
ls -lh
```

You should see:
- `fixedcoind` - Daemon
- `fixedcoin-cli` - CLI tools
- `fixedcoin-tx` - Transaction tools
- `fixedcoin-qt` - GUI wallet
- `fixedcoin-wallet` - Wallet tool

### Step 4: Install Binaries

```bash
# Move binaries to bin directory
mv fixedcoind fixedcoin-cli fixedcoin-tx fixedcoin-qt fixedcoin-wallet /var/fixedcoin/bin/

# Add to PATH
echo 'export PATH="/var/fixedcoin/bin:$PATH"' >> ~/.bashrc
source ~/.bashrc

# Verify installation
which fixedcoind
```

Expected output: `/var/fixedcoin/bin/fixedcoind`

Clean up:
```bash
cd /var/fixedcoin/downloads
rm -rf fixedcoin-25.0.0 fixedcoin-25.0.0-*.tar.gz
```

### Step 5: Configure Node

Create configuration file:

```bash
nano /var/fixedcoin/data/fixedcoin.conf
```

Paste the following configuration:

```ini
# RPC Settings
rpcuser=fixedcoin_rpc_user
rpcpassword=CHANGE_THIS_TO_SECURE_PASSWORD
rpcbind=127.0.0.1
rpcallowip=127.0.0.1
rpcport=24761

# Network Settings
listen=1
server=1
port=24768
maxconnections=125

# Official Seed Nodes
addnode=node1.fixedcoin.org
addnode=node2.fixedcoin.org

# Blockchain Settings
txindex=1
daemon=1

# ZMQ Notifications
zmqpubrawblock=tcp://127.0.0.1:24763
zmqpubrawtx=tcp://127.0.0.1:24764
zmqpubhashtx=tcp://127.0.0.1:24765
zmqpubhashblock=tcp://127.0.0.1:24766

# Wallet Configuration
wallet=miningcore
```

**Important:** Change `rpcuser` and `rpcpassword` to secure values. You can generate a secure password with:
```bash
openssl rand -hex 32
```

Save with `Ctrl + X`, then `Y`, then `Enter`.

Verify configuration:
```bash
cat /var/fixedcoin/data/fixedcoin.conf
```

### Step 6: Create Wallet

Start daemon manually for initial setup:

```bash
fixedcoind -datadir=/var/fixedcoin/data
```

Wait 5 seconds, then create wallet:

```bash
fixedcoin-cli -datadir=/var/fixedcoin/data createwallet "miningcore"
```

Expected output:
```json
{
  "name": "miningcore"
}
```

Generate receiving address:

```bash
fixedcoin-cli -datadir=/var/fixedcoin/data getnewaddress
```

Example output: `fix1qjpunqltsnm2a4jpp87zh0646p7ta7hq0n8q4rk`

**Save this address securely!**

### Step 7: Setup Systemd Service

Stop the manual daemon:

```bash
fixedcoin-cli -datadir=/var/fixedcoin/data stop
```

Wait 5 seconds for clean shutdown.

Create systemd service file:

```bash
sudo nano /etc/systemd/system/fixedcoind.service
```

Paste the following:

```ini
[Unit]
Description=FixedCoin Daemon
After=network.target

[Service]
Type=forking
User=root
Group=root
ExecStart=/var/fixedcoin/bin/fixedcoind -datadir=/var/fixedcoin/data -daemon
ExecStop=/var/fixedcoin/bin/fixedcoin-cli -datadir=/var/fixedcoin/data stop
Restart=on-failure
RestartSec=10
PIDFile=/var/fixedcoin/data/fixedcoind.pid
LimitNOFILE=8192
TimeoutStopSec=60

[Install]
WantedBy=multi-user.target
```

Save with `Ctrl + X`, then `Y`, then `Enter`.

### Step 8: Enable and Start Service

```bash
# Reload systemd
sudo systemctl daemon-reload

# Enable service on boot
sudo systemctl enable fixedcoind

# Start service
sudo systemctl start fixedcoind

# Check status
sudo systemctl status fixedcoind
```

Expected status: `active (running)`

### Step 9: Verify Node Operation

Check blockchain info:
```bash
fixedcoin-cli -datadir=/var/fixedcoin/data getblockchaininfo
```

Check network connections:
```bash
fixedcoin-cli -datadir=/var/fixedcoin/data getconnectioncount
```

Check peer information:
```bash
fixedcoin-cli -datadir=/var/fixedcoin/data getpeerinfo
```

Check if node is fully synced:
```bash
fixedcoin-cli -datadir=/var/fixedcoin/data getblockchaininfo | grep -E "blocks|headers"
```

View live logs:
```bash
sudo journalctl -u fixedcoind -f
```

Press `Ctrl + C` to exit logs.

## 🔧 Node Management Commands

### Service Management

```bash
# Start service
sudo systemctl start fixedcoind

# Stop service
sudo systemctl stop fixedcoind

# Restart service
sudo systemctl restart fixedcoind

# Check status
sudo systemctl status fixedcoind

# View logs
sudo journalctl -u fixedcoind -f

# View last 100 lines of logs
sudo journalctl -u fixedcoind -n 100
```

### Blockchain Commands

```bash
# Get blockchain information
fixedcoin-cli -datadir=/var/fixedcoin/data getblockchaininfo

# Get network information
fixedcoin-cli -datadir=/var/fixedcoin/data getnetworkinfo

# Get peer information
fixedcoin-cli -datadir=/var/fixedcoin/data getpeerinfo

# Get connection count
fixedcoin-cli -datadir=/var/fixedcoin/data getconnectioncount

# Get current block count
fixedcoin-cli -datadir=/var/fixedcoin/data getblockcount
```

### Wallet Commands

```bash
# Get wallet balance
fixedcoin-cli -datadir=/var/fixedcoin/data getbalance

# List all wallets
fixedcoin-cli -datadir=/var/fixedcoin/data listwallets

# Get new receiving address
fixedcoin-cli -datadir=/var/fixedcoin/data getnewaddress

# List recent transactions
fixedcoin-cli -datadir=/var/fixedcoin/data listtransactions

# Send FIX (replace with actual values)
fixedcoin-cli -datadir=/var/fixedcoin/data sendtoaddress "fix1..." 1.0

# Get transaction details
fixedcoin-cli -datadir=/var/fixedcoin/data gettransaction "txid"
```

## ⛏️ Mining FixedCoin

FixedCoin uses **SHA-256** algorithm, making it compatible with Bitcoin ASIC miners.

### Solo Mining Configuration

Add to `/var/fixedcoin/data/fixedcoin.conf`:

```ini
# Mining Configuration
gen=1
genproclimit=4
mineraddress=YOUR_FIXEDCOIN_ADDRESS
```

Replace `YOUR_FIXEDCOIN_ADDRESS` with your actual address (e.g., `fix1q...`).

Restart daemon:
```bash
sudo systemctl restart fixedcoind
```

Check mining status:
```bash
fixedcoin-cli -datadir=/var/fixedcoin/data getmininginfo
```

### Pool Mining

Configure any SHA-256 compatible mining software (cgminer, bfgminer, etc.) to point to a FixedCoin mining pool when available.

## 📊 Supply Schedule

| Block Range | Reward per Block | Blocks | Total FIX | Cumulative |
|-------------|------------------|--------|-----------|------------|
| 0 (Genesis) | 1.0 FIX | 1 | 1 | 1 |
| 1 (Premine) | 1,600.0 FIX | 1 | 1,600 | 1,601 |
| 2 - 4,199 | 1.0 FIX | 4,198 | 4,198 | 5,799 |
| 4,200 - 8,399 | 0.5 FIX | 4,200 | 2,100 | 7,899 |
| 8,400 - 12,599 | 0.25 FIX | 4,200 | 1,050 | 8,949 |
| 12,600 - 16,799 | 0.125 FIX | 4,200 | 525 | 9,474 |
| 16,800 - 20,999 | 0.0625 FIX | 4,200 | 262.5 | 9,736.5 |
| 21,000 - 25,199 | 0.03125 FIX | 4,200 | 131.25 | 9,867.75 |
| 25,200 - 29,399 | 0.015625 FIX | 4,200 | 65.625 | 9,933.375 |
| ... | (continues halving) | ... | ... | ... |
| 113,400+ | 0 FIX | ∞ | 0 | 10,000 |
| **TOTAL** | - | - | **10,000 FIX** | - |

**Premine Details:**
- **Block 1:** 1,600 FIX (16% of total supply)
- **Purpose:** Ecosystem development, initial liquidity, community incentives
- **Mining starts:** Block 2 onwards with standard halving schedule

After block 113,400 (2 years), no new coins are created. Network security is maintained through transaction fees.

## 🔐 Security Best Practices

### Wallet Security

- ✅ **Backup wallet regularly:** `wallet.dat` file is located in `/var/fixedcoin/data/`
- ✅ **Encrypt wallet:** Use `encryptwallet` command with strong passphrase
- ✅ **Secure private keys:** Never share your wallet.dat or private keys
- ✅ **Use strong RPC passwords:** Change default credentials in fixedcoin.conf

### Server Security

- ✅ **Firewall:** Configure UFW to allow only necessary ports
- ✅ **SSH security:** Use SSH keys, disable password authentication
- ✅ **Regular updates:** Keep Ubuntu and FixedCoin up to date
- ✅ **Monitoring:** Set up monitoring and alerting

### Firewall Configuration

```bash
# Enable UFW
sudo ufw enable

# Allow SSH
sudo ufw allow 22/tcp

# Allow FixedCoin P2P
sudo ufw allow 24768/tcp

# Check status
sudo ufw status
```

**Note:** RPC port 24761 should NOT be exposed to the internet. It's for local use only.

## 🐛 Troubleshooting

### Node won't start

```bash
# Check service status
sudo systemctl status fixedcoind

# View error logs
sudo journalctl -u fixedcoind -n 50

# Check debug.log
tail -f /var/fixedcoin/data/debug.log
```

### No connections to network

```bash
# Verify configuration
cat /var/fixedcoin/data/fixedcoin.conf

# Test node connectivity
ping node1.fixedcoin.org
ping node2.fixedcoin.org

# Manually add nodes
fixedcoin-cli -datadir=/var/fixedcoin/data addnode "node1.fixedcoin.org:24768" "add"
fixedcoin-cli -datadir=/var/fixedcoin/data addnode "node2.fixedcoin.org:24768" "add"
```

### Wallet issues

```bash
# List loaded wallets
fixedcoin-cli -datadir=/var/fixedcoin/data listwallets

# Load wallet manually
fixedcoin-cli -datadir=/var/fixedcoin/data loadwallet "miningcore"

# Get wallet info
fixedcoin-cli -datadir=/var/fixedcoin/data getwalletinfo
```

### Blockchain sync stuck

```bash
# Check current block
fixedcoin-cli -datadir=/var/fixedcoin/data getblockcount

# Check peer blocks
fixedcoin-cli -datadir=/var/fixedcoin/data getpeerinfo | grep -i "synced_blocks"

# Restart daemon
sudo systemctl restart fixedcoind
```

## ❓ Frequently Asked Questions

### What is the premine for?
The 1,600 FIX premine (16% of total supply) at block 1 provides initial liquidity for exchanges, funds community development, incentivizes early adopters, and ensures ecosystem sustainability. This is a transparent, one-time allocation locked in the blockchain forever.

### What happens after all coins are mined?
After block 113,400 (2 years), miners are compensated solely through transaction fees. This ensures long-term network security without inflation.

### Can the code be updated later?
No. The repository will be archived after block 1. No updates, no bug fixes, no changes. Ever. This is by design.

### Why only 10,000 coins?
To create the ultimate experiment in digital scarcity. FixedCoin is 2,100x rarer than Bitcoin, making it one of the scarcest cryptocurrencies ever created.

### Is this a joke/meme coin?
No. FixedCoin is a serious experiment in protocol immutability and extreme scarcity. It's built on Bitcoin's proven codebase with SHA-256 security.

### How can I contribute?
Build tools, wallets, services, and applications. The protocol is fixed, but the ecosystem is yours to create. Everything must be built by the community.

### What makes FixedCoin different from Bitcoin?
- **Ultra-rare supply:** 10,000 vs 21,000,000
- **Premine:** 1,600 FIX for ecosystem development
- **Absolute immutability:** No updates after archive
- **Faster distribution:** 2 years vs 140 years
- **Community-driven:** No foundation or central authority

### Is it safe to use?
FixedCoin uses Bitcoin's proven codebase and SHA-256 algorithm. However, as with all cryptocurrencies, use at your own risk. See the [Disclaimer](#️-disclaimer) section.

## 📚 Additional Resources

- **Source Code:** [GitHub Repository](https://github.com/Fixed-Blockchain/fixedcoin)
- **Releases:** [Download Page](https://github.com/Fixed-Blockchain/fixedcoin/releases/tag/FIX)
- **Block Explorer:** [explorer.fixedcoin.org](https://explorer.fixedcoin.org)
- **Website:** [fixedcoin.org](https://fixedcoin.org)

## ⚠️ Disclaimer

FixedCoin is an experimental cryptocurrency project. The ultra-limited supply (10,000 FIX) including a 1,600 FIX premine and unique economic model create an unprecedented experiment in digital scarcity.

**Key Risks:**
- 16% premine may affect initial distribution and decentralization
- Experimental tokenomics with no prior precedent
- Repository will be archived - no future development or bug fixes
- Network security post-distribution depends entirely on transaction fees
- Extremely low supply may lead to high price volatility
- No central authority, foundation, or ongoing support

**This is not financial advice. Do Your Own Research (DYOR).**

Only participate with funds you can afford to lose entirely.

## 📜 License

FixedCoin is released under the MIT License. See [LICENSE](LICENSE) for details.

## 🔒 The Fixed Promise

Once block 1 is mined, this repository will be **permanently archived**:

- ✅ No code changes
- ✅ No governance
- ✅ No updates
- ✅ No ICO or VC funding
- ✅ No foundation
- ✅ Pure immutability

**Block 0:** Genesis (1 FIX)  
**Block 1:** Premine (1,600 FIX) - Then archived forever  
**Block 2+:** Mining begins (8,398 FIX over 2 years)

**Everything is Fixed. Forever.**

---

**Built on Bitcoin's proven technology. Secured by SHA-256. Limited to 10,000 coins.**

*Always verify file integrity by checking SHA256 hashes before running any binaries.*
