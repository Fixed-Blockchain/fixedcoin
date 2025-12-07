# Copyright (c) 2023-present The Bitcoin Core developers
# Copyright (c) 2025 The FixedCoin Core developers
# Distributed under the MIT software license, see the accompanying
# file COPYING or https://opensource.org/license/mit/.

include(AddWindowsResources)

configure_file(${PROJECT_SOURCE_DIR}/cmake/fixedcoin-build-config.h.in fixedcoin-build-config.h USE_SOURCE_PERMISSIONS @ONLY)
include_directories(${CMAKE_CURRENT_BINARY_DIR} ${CMAKE_CURRENT_SOURCE_DIR})

#=============================
# Subprojects
#=============================
# Subprojects include subdirectories that do or could have tests
# and/or benchmark binaries, such as all subtrees and univalue.
# These need to be included before CMAKE_*_OUTPUT_DIRECTORY variables
# are set, so output locations of subproject tests and libraries are
# not overridden.
include(../cmake/crc32c.cmake)
include(../cmake/leveldb.cmake)
include(../cmake/minisketch.cmake)
add_subdirectory(univalue)
#=============================
# secp256k1 subtree
#=============================
message("")
message("Configuring secp256k1 subtree...")
set(SECP256K1_DISABLE_SHARED ON CACHE BOOL "" FORCE)
set(SECP256K1_ENABLE_MODULE_ECDH OFF CACHE BOOL "" FORCE)
set(SECP256K1_ENABLE_MODULE_RECOVERY ON CACHE BOOL "" FORCE)
set(SECP256K1_ENABLE_MODULE_MUSIG OFF CACHE BOOL "" FORCE)
set(SECP256K1_BUILD_BENCHMARK OFF CACHE BOOL "" FORCE)
set(SECP256K1_BUILD_TESTS ${BUILD_TESTS} CACHE BOOL "" FORCE)
set(SECP256K1_BUILD_EXHAUSTIVE_TESTS ${BUILD_TESTS} CACHE BOOL "" FORCE)
if(NOT BUILD_TESTS)
  # Always skip the ctime tests, if we are building no other tests.
  # Otherwise, they are built if Valgrind is available. See SECP256K1_VALGRIND.
  set(SECP256K1_BUILD_CTIME_TESTS ${BUILD_TESTS} CACHE BOOL "" FORCE)
endif()
set(SECP256K1_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
include(GetTargetInterface)
# -fsanitize and related flags apply to both C++ and C,
# so we can pass them down to libsecp256k1 as CFLAGS and LDFLAGS.
get_target_interface(SECP256K1_APPEND_CFLAGS "" sanitize_interface COMPILE_OPTIONS)
string(STRIP "${SECP256K1_APPEND_CFLAGS} ${APPEND_CPPFLAGS}" SECP256K1_APPEND_CFLAGS)
string(STRIP "${SECP256K1_APPEND_CFLAGS} ${APPEND_CFLAGS}" SECP256K1_APPEND_CFLAGS)
set(SECP256K1_APPEND_CFLAGS ${SECP256K1_APPEND_CFLAGS} CACHE STRING "" FORCE)
get_target_interface(SECP256K1_APPEND_LDFLAGS "" sanitize_interface LINK_OPTIONS)
string(STRIP "${SECP256K1_APPEND_LDFLAGS} ${APPEND_LDFLAGS}" SECP256K1_APPEND_LDFLAGS)
set(SECP256K1_APPEND_LDFLAGS ${SECP256K1_APPEND_LDFLAGS} CACHE STRING "" FORCE)
# We want to build libsecp256k1 with the most tested RelWithDebInfo configuration.
enable_language(C)
foreach(config IN LISTS CMAKE_BUILD_TYPE CMAKE_CONFIGURATION_TYPES)
  if(config STREQUAL "")
    continue()
  endif()
  string(TOUPPER "${config}" config)
  set(CMAKE_C_FLAGS_${config} "${CMAKE_C_FLAGS_RELWITHDEBINFO}")
endforeach()
# If the CFLAGS environment variable is defined during building depends
# and configuring this build system, its content might be duplicated.
if(DEFINED ENV{CFLAGS})
  deduplicate_flags(CMAKE_C_FLAGS)
endif()
set(CMAKE_EXPORT_COMPILE_COMMANDS OFF)
add_subdirectory(secp256k1)
set_target_properties(secp256k1 PROPERTIES
  EXCLUDE_FROM_ALL TRUE
)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Set top-level target output locations.
if(NOT CMAKE_RUNTIME_OUTPUT_DIRECTORY)
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)
endif()
if(NOT CMAKE_LIBRARY_OUTPUT_DIRECTORY)
  set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
endif()
if(NOT CMAKE_ARCHIVE_OUTPUT_DIRECTORY)
  set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
endif()

add_custom_target(generate_build_info
  BYPRODUCTS ${PROJECT_BINARY_DIR}/src/fixedcoin-build-info.h
  COMMAND ${CMAKE_COMMAND} -DBUILD_INFO_HEADER_PATH=${PROJECT_BINARY_DIR}/src/fixedcoin-build-info.h -DSOURCE_DIR=${PROJECT_SOURCE_DIR} -P ${PROJECT_SOURCE_DIR}/cmake/script/GenerateBuildInfo.cmake
  COMMENT "Generating fixedcoin-build-info.h"
  VERBATIM
)
add_library(fixedcoin_clientversion STATIC EXCLUDE_FROM_ALL
  clientversion.cpp
)
target_link_libraries(fixedcoin_clientversion
  PRIVATE
    core_interface
)
add_dependencies(fixedcoin_clientversion generate_build_info)

add_subdirectory(crypto)
add_subdirectory(util)
if(WITH_MULTIPROCESS)
  add_subdirectory(ipc)
endif()

add_library(fixedcoin_consensus STATIC EXCLUDE_FROM_ALL
  arith_uint256.cpp
  consensus/merkle.cpp
  consensus/tx_check.cpp
  hash.cpp
  primitives/block.cpp
  primitives/transaction.cpp
  pubkey.cpp
  script/interpreter.cpp
  script/script.cpp
  script/script_error.cpp
  uint256.cpp
)
target_link_libraries(fixedcoin_consensus
  PRIVATE
    core_interface
    fixedcoin_crypto
    secp256k1
)

if(WITH_ZMQ)
  add_subdirectory(zmq)
endif()

# Home for common functionality shared by different executables and libraries.
# Similar to `fixedcoin_util` library, but higher-level.
add_library(fixedcoin_common STATIC EXCLUDE_FROM_ALL
  addresstype.cpp
  base58.cpp
  bech32.cpp
  chain.cpp
  chainparams.cpp
  chainparamsbase.cpp
  coins.cpp
  common/args.cpp
  common/bloom.cpp
  common/config.cpp
  common/init.cpp
  common/interfaces.cpp
  common/messages.cpp
  common/netif.cpp
  common/pcp.cpp
  common/run_command.cpp
  common/settings.cpp
  common/signmessage.cpp
  common/system.cpp
  common/url.cpp
  compressor.cpp
  core_read.cpp
  core_write.cpp
  deploymentinfo.cpp
  external_signer.cpp
  init/common.cpp
  kernel/chainparams.cpp
  key.cpp
  key_io.cpp
  merkleblock.cpp
  net_permissions.cpp
  net_types.cpp
  netaddress.cpp
  netbase.cpp
  outputtype.cpp
  policy/feerate.cpp
  policy/policy.cpp
  pow.cpp
  protocol.cpp
  psbt.cpp
  rpc/rawtransaction_util.cpp
  rpc/request.cpp
  rpc/util.cpp
  scheduler.cpp
  script/descriptor.cpp
  script/miniscript.cpp
  script/parsing.cpp
  script/sign.cpp
  script/signingprovider.cpp
  script/solver.cpp
)
target_link_libraries(fixedcoin_common
  PRIVATE
    core_interface
    fixedcoin_consensus
    fixedcoin_util
    univalue
    secp256k1
    Boost::headers
    $<TARGET_NAME_IF_EXISTS:USDT::headers>
    $<$<PLATFORM_ID:Windows>:ws2_32>
)

include(InstallBinaryComponent)

if(ENABLE_WALLET)
  add_subdirectory(wallet)

  if(BUILD_WALLET_TOOL)
    add_executable(fixedcoin-wallet
      fixedcoin-wallet.cpp
      init/fixedcoin-wallet.cpp
      wallet/wallettool.cpp
    )
    add_windows_resources(fixedcoin-wallet fixedcoin-wallet-res.rc)
    target_link_libraries(fixedcoin-wallet
      core_interface
      fixedcoin_wallet
      fixedcoin_common
      fixedcoin_util
      Boost::headers
    )
    install_binary_component(fixedcoin-wallet HAS_MANPAGE)
  endif()
endif()


# P2P and RPC server functionality used by `fixedcoind` and `fixedcoin-qt` executables.
add_library(fixedcoin_node STATIC EXCLUDE_FROM_ALL
  addrdb.cpp
  addrman.cpp
  banman.cpp
  bip324.cpp
  blockencodings.cpp
  blockfilter.cpp
  consensus/tx_verify.cpp
  dbwrapper.cpp
  deploymentstatus.cpp
  flatfile.cpp
  headerssync.cpp
  httprpc.cpp
  httpserver.cpp
  i2p.cpp
  index/base.cpp
  index/blockfilterindex.cpp
  index/coinstatsindex.cpp
  index/txindex.cpp
  init.cpp
  kernel/chain.cpp
  kernel/checks.cpp
  kernel/coinstats.cpp
  kernel/context.cpp
  kernel/cs_main.cpp
  kernel/disconnected_transactions.cpp
  kernel/mempool_removal_reason.cpp
  mapport.cpp
  net.cpp
  net_processing.cpp
  netgroup.cpp
  node/abort.cpp
  node/blockmanager_args.cpp
  node/blockstorage.cpp
  node/caches.cpp
  node/chainstate.cpp
  node/chainstatemanager_args.cpp
  node/coin.cpp
  node/coins_view_args.cpp
  node/connection_types.cpp
  node/context.cpp
  node/database_args.cpp
  node/eviction.cpp
  node/interface_ui.cpp
  node/interfaces.cpp
  node/kernel_notifications.cpp
  node/mempool_args.cpp
  node/mempool_persist.cpp
  node/mempool_persist_args.cpp
  node/miner.cpp
  node/mini_miner.cpp
  node/minisketchwrapper.cpp
  node/peerman_args.cpp
  node/psbt.cpp
  node/timeoffsets.cpp
  node/transaction.cpp
  node/txdownloadman_impl.cpp
  node/txreconciliation.cpp
  node/utxo_snapshot.cpp
  node/warnings.cpp
  noui.cpp
  policy/ephemeral_policy.cpp
  policy/fees.cpp
  policy/fees_args.cpp
  policy/packages.cpp
  policy/rbf.cpp
  policy/settings.cpp
  policy/truc_policy.cpp
  rest.cpp
  rpc/blockchain.cpp
  rpc/external_signer.cpp
  rpc/fees.cpp
  rpc/mempool.cpp
  rpc/mining.cpp
  rpc/net.cpp
  rpc/node.cpp
  rpc/output_script.cpp
  rpc/rawtransaction.cpp
  rpc/server.cpp
  rpc/server_util.cpp
  rpc/signmessage.cpp
  rpc/txoutproof.cpp
  script/sigcache.cpp
  signet.cpp
  torcontrol.cpp
  txdb.cpp
  txmempool.cpp
  txorphanage.cpp
  txrequest.cpp
  validation.cpp
  validationinterface.cpp
  versionbits.cpp
  $<$<TARGET_EXISTS:fixedcoin_wallet>:wallet/init.cpp>
  $<$<NOT:$<TARGET_EXISTS:fixedcoin_wallet>>:dummywallet.cpp>
)
target_link_libraries(fixedcoin_node
  PRIVATE
    core_interface
    fixedcoin_common
    fixedcoin_util
    $<TARGET_NAME_IF_EXISTS:fixedcoin_zmq>
    leveldb
    minisketch
    univalue
    Boost::headers
    $<TARGET_NAME_IF_EXISTS:libevent::core>
    $<TARGET_NAME_IF_EXISTS:libevent::extra>
    $<TARGET_NAME_IF_EXISTS:libevent::pthreads>
    $<TARGET_NAME_IF_EXISTS:USDT::headers>
)


# FixedCoin Core fixedcoind.
if(BUILD_DAEMON)
  add_executable(fixedcoind
    fixedcoind.cpp
    init/fixedcoind.cpp
  )
  add_windows_resources(fixedcoind fixedcoind-res.rc)
  target_link_libraries(fixedcoind
    core_interface
    fixedcoin_node
    $<TARGET_NAME_IF_EXISTS:fixedcoin_wallet>
  )
  install_binary_component(fixedcoind HAS_MANPAGE)
endif()
if(WITH_MULTIPROCESS AND BUILD_DAEMON)
  add_executable(fixedcoin-node
    fixedcoind.cpp
    init/fixedcoin-node.cpp
  )
  target_link_libraries(fixedcoin-node
    core_interface
    fixedcoin_node
    fixedcoin_ipc
    $<TARGET_NAME_IF_EXISTS:fixedcoin_wallet>
  )
  install_binary_component(fixedcoin-node)
endif()

if(WITH_MULTIPROCESS AND BUILD_TESTS)
    # fixedcoin_ipc_test library target is defined here in src/CMakeLists.txt
    # instead of src/test/CMakeLists.txt so capnp files in src/test/ are able to
    # reference capnp files in src/ipc/capnp/ by relative path. The Cap'n Proto
    # compiler only allows importing by relative path when the importing and
    # imported files are underneath the same compilation source prefix, so the
    # source prefix must be src/, not src/test/
    add_library(fixedcoin_ipc_test STATIC EXCLUDE_FROM_ALL
      test/ipc_test.cpp
    )
    target_capnp_sources(fixedcoin_ipc_test ${PROJECT_SOURCE_DIR}
      test/ipc_test.capnp
    )
    add_dependencies(fixedcoin_ipc_test fixedcoin_ipc_headers)
endif()


add_library(fixedcoin_cli STATIC EXCLUDE_FROM_ALL
  compat/stdin.cpp
  rpc/client.cpp
)
target_link_libraries(fixedcoin_cli
  PUBLIC
    core_interface
    univalue
)


# FixedCoin Core RPC client
if(BUILD_CLI)
  add_executable(fixedcoin-cli fixedcoin-cli.cpp)
  add_windows_resources(fixedcoin-cli fixedcoin-cli-res.rc)
  target_link_libraries(fixedcoin-cli
    core_interface
    fixedcoin_cli
    fixedcoin_common
    fixedcoin_util
    libevent::core
    libevent::extra
  )
  install_binary_component(fixedcoin-cli HAS_MANPAGE)
endif()


if(BUILD_TX)
  add_executable(fixedcoin-tx fixedcoin-tx.cpp)
  add_windows_resources(fixedcoin-tx fixedcoin-tx-res.rc)
  target_link_libraries(fixedcoin-tx
    core_interface
    fixedcoin_common
    fixedcoin_util
    univalue
  )
  install_binary_component(fixedcoin-tx HAS_MANPAGE)
endif()


if(BUILD_UTIL)
  add_executable(fixedcoin-util fixedcoin-util.cpp)
  add_windows_resources(fixedcoin-util fixedcoin-util-res.rc)
  target_link_libraries(fixedcoin-util
    core_interface
    fixedcoin_common
    fixedcoin_util
  )
  install_binary_component(fixedcoin-util HAS_MANPAGE)
endif()


if(BUILD_GUI)
  add_subdirectory(qt)
endif()


if(BUILD_KERNEL_LIB)
  add_subdirectory(kernel)
endif()

if(BUILD_UTIL_CHAINSTATE)
  add_executable(fixedcoin-chainstate
    fixedcoin-chainstate.cpp
  )
  # TODO: The `SKIP_BUILD_RPATH` property setting can be deleted
  #       in the future after reordering Guix script commands to
  #       perform binary checks after the installation step.
  # Relevant discussions:
  # - https://github.com/hebasto/fixedcoin/pull/236#issuecomment-2183120953
  # - https://github.com/fixedcoin/fixedcoin/pull/30312#issuecomment-2191235833
  set_target_properties(fixedcoin-chainstate PROPERTIES
    SKIP_BUILD_RPATH OFF
  )
  target_link_libraries(fixedcoin-chainstate
    PRIVATE
      core_interface
      fixedcoinkernel
  )
endif()


add_subdirectory(test/util)
if(BUILD_BENCH)
  add_subdirectory(bench)
endif()

if(BUILD_TESTS)
  add_subdirectory(test)
endif()

if(BUILD_FUZZ_BINARY)
  add_subdirectory(test/fuzz)
endif()
