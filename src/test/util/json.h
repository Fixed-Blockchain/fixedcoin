// Copyright (c) 2023-present The Bitcoin Core developers
// Copyright (c) 2025 The FixedCoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef FIXEDCOIN_TEST_UTIL_JSON_H
#define FIXEDCOIN_TEST_UTIL_JSON_H

#include <univalue.h>

#include <string_view>

UniValue read_json(std::string_view jsondata);

#endif // FIXEDCOIN_TEST_UTIL_JSON_H
