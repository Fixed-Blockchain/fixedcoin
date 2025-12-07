# Copyright (c) 2024-present The Bitcoin Core developers
# Copyright (c) 2025 The FixedCoin Core developers
# Distributed under the MIT software license, see the accompanying
# file COPYING or https://opensource.org/license/mit/.

set(CMAKE_AUTOMOC_MOC_OPTIONS "-p${CMAKE_CURRENT_SOURCE_DIR}")

add_executable(test_fixedcoin-qt
  apptests.cpp
  optiontests.cpp
  rpcnestedtests.cpp
  test_main.cpp
  uritests.cpp
  util.cpp
  ../../init/fixedcoin-qt.cpp
)

target_link_libraries(test_fixedcoin-qt
  core_interface
  fixedcoinqt
  test_util
  fixedcoin_node
  Boost::headers
  Qt5::Test
)

import_plugins(test_fixedcoin-qt)

if(ENABLE_WALLET)
  target_sources(test_fixedcoin-qt
    PRIVATE
      addressbooktests.cpp
      wallettests.cpp
      ../../wallet/test/wallet_test_fixture.cpp
  )
endif()

add_test(NAME test_fixedcoin-qt
  COMMAND test_fixedcoin-qt
)
if(WIN32 AND VCPKG_TARGET_TRIPLET)
  # On Windows, vcpkg configures Qt with `-opengl dynamic`, which makes
  # the "minimal" platform plugin unusable due to internal Qt bugs.
  set_tests_properties(test_fixedcoin-qt PROPERTIES
    ENVIRONMENT "QT_QPA_PLATFORM=windows"
  )
endif()

install_binary_component(test_fixedcoin-qt)
