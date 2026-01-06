# FixedCoin 🔒

![FixedCoin Logo](https://github.com/Fixed-Blockchain/fixedcoin/blob/main/fix.png)

![Version](https://img.shields.io/badge/version-29.1.2-blue.svg)
![License](https://img.shields.io/badge/license-MIT-green.svg)
![Supply](https://img.shields.io/badge/supply-10%2C000%20FIX-orange.svg)
![Algorithm](https://img.shields.io/badge/algorithm-SHA--256-blue.svg)

**🌐 [Website](https://fixedcoin.org) | 🔍 [Explorer](https://explorer.fixedcoin.org) | 📦 [Releases](https://github.com/Fixed-Blockchain/fixedcoin/releases)**

---

## 📚 Table of Contents

- [What is FixedCoin?](#-what-is-fixedcoin)
- [Technical Specifications](#-technical-specifications)
- [Network](#-network)
- [Downloads](#-downloads)
- [Quick Start Guide](#-quick-start-guide)
- [Ubuntu Server Setup](#️-ubuntu-server-2204-node-setup)
- [Node Management Commands](#-node-management-commands)
- [Mining FixedCoin](#️-mining-fixedcoin)
- [Security Best Practices](#-security-best-practices)
- [Troubleshooting](#-troubleshooting)
- [License](#-license)

---

## 🔐 What is FixedCoin?

FixedCoin is an ultra-rare cryptocurrency with a total supply of only **10,000 FIX**. Built on Bitcoin's proven codebase and secured by SHA-256 mining, FixedCoin represents the ultimate experiment in digital scarcity.

## 💎 Technical Specifications

| Parameter | Value |
|-----------|-------|
| **Total Supply** | 10,000 FIX |
| **Block Reward** | 1 FIX (initial) |
| **Halving Interval** | 4,200 blocks |
| **Mining Algorithm** | SHA-256 |
| **Block Time** | 10 minutes |
| **Difficulty Adjustment** | ASERT (every block) |
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

### Latest Release: v29.1.2

Download from [GitHub Releases](https://github.com/Fixed-Blockchain/fixedcoin/releases/tag/v29.1.2)

#### Windows

**Setup Installer (Recommended)**
- [fixedcoin-29.1.2-win64-setup.exe](https://github.com/Fixed-Blockchain/fixedcoin/releases/download/v29.1.2/fixedcoin-29.1.2-win64-setup.exe)

**Portable Archive**
- [fixedcoin-29.1.2-win64.zip](https://github.com/Fixed-Blockchain/fixedcoin/releases/download/v29.1.2/fixedcoin-29.1.2-win64.zip)

#### macOS

**Disk Image (Recommended)**
- [fixedcoin-29.1.2-x86_64-apple-darwin.dmg](https://github.com/Fixed-Blockchain/fixedcoin/releases/download/v29.1.2/fixedcoin-29.1.2-x86_64-apple-darwin-dmg.zip)

**Archive (Intel)**
- [fixedcoin-29.1.2-x86_64-apple-darwin.tar.gz](https://github.com/Fixed-Blockchain/fixedcoin/releases/download/v29.1.2/fixedcoin-29.1.2-x86_64-apple-darwin-tar.zip)

#### Linux

**x86_64 (64-bit Intel/AMD)**
- [fixedcoin-29.1.2-x86_64-linux-gnu.tar.gz](https://github.com/Fixed-Blockchain/fixedcoin/releases/download/v29.1.2/fixedcoin-29.1.2-x86_64-linux-gnu.tar.gz)

**ARM64 (Raspberry Pi, ARM servers)**
- [fixedcoin-29.1.2-aarch64-linux-gnu.tar.gz](https://github.com/Fixed-Blockchain/fixedcoin/releases/download/v29.1.2/fixedcoin-29.1.2-aarch64-linux-gnu.tar.gz)

## 🚀 Quick Start Guide

### Windows Installation

**Using Installer (Recommended):**
1. Download [fixedcoin-29.1.2-win64-setup.exe](https://github.com/Fixed-Blockchain/fixedcoin/releases/download/v29.1.2/fixedcoin-29.1.2-win64-setup.exe)
2. Run the installer and follow the setup wizard
3. Launch FixedCoin from Start Menu
4. Wait for blockchain synchronization

**Using Portable Archive:**
1. Download [fixedcoin-29.1.2-win64.zip](https://github.com/Fixed-Blockchain/fixedcoin/releases/download/v29.1.2/fixedcoin-29.1.2-win64.zip)
2. Extract the archive to a folder (e.g., `C:\FixedCoin`)
3. Run `fixedcoin-qt.exe` to start the wallet
4. Wait for blockchain synchronization

### macOS Installation

**Using Disk Image (Recommended):**
1. Download [fixedcoin-29.1.2-x86_64-apple-darwin.dmg](https://github.com/Fixed-Blockchain/fixedcoin/releases/download/v29.1.2/fixedcoin-29.1.2-x86_64-apple-darwin-dmg.zip)
2. Open the DMG file
3. Drag FixedCoin to Applications folder
4. Launch FixedCoin from Applications
5. Wait for blockchain synchronization

**Using Archive:**
```bash
# Download
curl -L -O https://github.com/Fixed-Blockchain/fixedcoin/releases/download/v29.1.2/fixedcoin-29.1.2-x86_64-apple-darwin-tar.zip

# Extract
tar -xzf fixedcoin-29.1.2-x86_64-apple-darwin.tar.gz

# Make binaries executable
chmod +x fixedcoin-29.1.2/bin/*

# Run GUI wallet
./fixedcoin-29.1.2/bin/fixedcoin-qt

# Or run daemon in background
./fixedcoin-29.1.2/bin/fixedcoind -daemon
```

### Linux Desktop Installation

**For x86_64 systems:**
```bash
# Download
wget https://github.com/Fixed-Blockchain/fixedcoin/releases/download/v29.1.2/fixedcoin-29.1.2-x86_64-linux-gnu.tar.gz

# Extract
tar -xzf fixedcoin-29.1.2-x86_64-linux-gnu.tar.gz

# Make binaries executable
chmod +x fixedcoin-29.1.2/bin/*

# Run GUI wallet
./fixedcoin-29.1.2/bin/fixedcoin-qt

# Or run daemon in background
./fixedcoin-29.1.2/bin/fixedcoind -daemon
```

**For ARM64 systems (Raspberry Pi, etc.):**
```bash
# Download
wget https://github.com/Fixed-Blockchain/fixedcoin/releases/download/v29.1.2/fixedcoin-29.1.2-aarch64-linux-gnu.tar.gz

# Extract
tar -xzf fixedcoin-29.1.2-aarch64-linux-gnu.tar.gz

# Make binaries executable
chmod +x fixedcoin-29.1.2/bin/*

# Run GUI wallet
./fixedcoin-29.1.2/bin/fixedcoin-qt

# Or run daemon in background
./fixedcoin-29.1.2/bin/fixedcoind -daemon
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

### Step 2: Download and Install Binaries
```bash
cd /var/fixedcoin/downloads

# For x86_64 systems (Intel/AMD)
wget https://github.com/Fixed-Blockchain/fixedcoin/releases/download/v29.1.2/fixedcoin-29.1.2-x86_64-linux-gnu.tar.gz

# OR for ARM64 systems (Raspberry Pi, ARM servers)
# wget https://github.com/Fixed-Blockchain/fixedcoin/releases/download/v29.1.2/fixedcoin-29.1.2-aarch64-linux-gnu.tar.gz

# Extract
tar -xzf fixedcoin-29.1.2-x86_64-linux-gnu.tar.gz

# Make binaries executable
chmod +x fixedcoin-29.1.2/bin/*

# Move binaries to bin directory
mv fixedcoin-29.1.2/bin/* /var/fixedcoin/bin/

# Add to PATH
echo 'export PATH="/var/fixedcoin/bin:$PATH"' >> ~/.bashrc
source ~/.bashrc

# Verify installation
which fixedcoind
```

Clean up:
```bash
rm -rf fixedcoin-29.1.2 fixedcoin-29.1.2-*.tar.gz
```

### Step 3: Configure Node

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
wallet=YOUR_WAALLET_NAME
```

**Important:** Generate a secure password with:
```bash
openssl rand -hex 32
```

### Step 4: Create Wallet

Start daemon manually for initial setup:
```bash
fixedcoind -datadir=/var/fixedcoin/data
```

Wait 5 seconds, then create wallet:
```bash
fixedcoin-cli -datadir=/var/fixedcoin/data createwallet "miningcore"
```

Generate receiving address:
```bash
fixedcoin-cli -datadir=/var/fixedcoin/data getnewaddress
```

**Save this address securely!**

### Step 5: Setup Systemd Service

Stop the manual daemon:
```bash
fixedcoin-cli -datadir=/var/fixedcoin/data stop
```

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

### Step 6: Enable and Start Service
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
```

### Blockchain Commands
```bash
# Get blockchain information
fixedcoin-cli -datadir=/var/fixedcoin/data getblockchaininfo

# Get network information
fixedcoin-cli -datadir=/var/fixedcoin/data getnetworkinfo

# Get connection count
fixedcoin-cli -datadir=/var/fixedcoin/data getconnectioncount

# Get current block count
fixedcoin-cli -datadir=/var/fixedcoin/data getblockcount
```

### Wallet Commands
```bash
# Get wallet balance
fixedcoin-cli -datadir=/var/fixedcoin/data getbalance

# Get new receiving address
fixedcoin-cli -datadir=/var/fixedcoin/data getnewaddress

# List recent transactions
fixedcoin-cli -datadir=/var/fixedcoin/data listtransactions

# Send FIX
fixedcoin-cli -datadir=/var/fixedcoin/data sendtoaddress "fix1..." 1.0
```

## 🔨 Build from Source

### Quick Build (using system libraries)
```bash
# Install dependencies
sudo apt install build-essential cmake pkg-config libboost-dev libevent-dev libsqlite3-dev

# Optional: GUI support
sudo apt install qtbase5-dev qttools5-dev qttools5-dev-tools

# Optional: ZMQ support
sudo apt install libzmq3-dev

# Clone and build
git clone https://github.com/Fixed-Blockchain/fixedcoin.git
cd fixedcoin
cmake -B build
cmake --build build -j$(nproc)

# Binaries are in build/bin/
./build/bin/fixedcoind --version
```

### Static Build (using depends)

For portable binaries, use the depends system:
```bash
# Build dependencies (takes 30-60 min)
cd depends
make HOST=x86_64-pc-linux-gnu -j$(nproc)
cd ..

# Build with static linking
cmake -B build --toolchain depends/x86_64-pc-linux-gnu/toolchain.cmake
cmake --build build -j$(nproc)
```

> **Note:** FixedCoin v29 uses CMake (not Autotools). There is no `./configure` or `autogen.sh`.

## 🔐 Security Best Practices

### Wallet Security

- ✅ **Backup wallet regularly:** `wallet.dat` file is located in `/var/fixedcoin/data/`
- ✅ **Encrypt wallet:** Use `encryptwallet` command with strong passphrase
- ✅ **Secure private keys:** Never share your wallet.dat or private keys
- ✅ **Use strong RPC passwords:** Change default credentials in fixedcoin.conf

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

**Note:** RPC port 24761 should NOT be exposed to the internet.

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
```

## 📜 License

FixedCoin is released under the MIT License. See [LICENSE](LICENSE) for details.

---

**Built on Bitcoin's proven technology. Secured by SHA-256. Limited to 10,000 coins.**
