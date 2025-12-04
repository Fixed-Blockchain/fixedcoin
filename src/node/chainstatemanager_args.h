// Copyright (c) 2022 The FixedCoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef FIXEDCOIN_NODE_CHAINSTATEMANAGER_ARGS_H
#define FIXEDCOIN_NODE_CHAINSTATEMANAGER_ARGS_H

#include <util/result.h>
#include <validation.h>

class ArgsManager;

/** -par default (number of script-checking threads, 0 = auto) */
static constexpr int DEFAULT_SCRIPTCHECK_THREADS{0};

namespace node {
[[nodiscard]] util::Result<void> ApplyArgsManOptions(const ArgsManager& args, ChainstateManager::Options& opts);
} // namespace node

#endif // FIXEDCOIN_NODE_CHAINSTATEMANAGER_ARGS_H
