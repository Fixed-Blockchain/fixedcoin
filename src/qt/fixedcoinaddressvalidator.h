// Copyright (c) 2011-2020 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef FIXEDCOIN_QT_FIXEDCOINADDRESSVALIDATOR_H
#define FIXEDCOIN_QT_FIXEDCOINADDRESSVALIDATOR_H

#include <QValidator>

/** Base58 entry widget validator, checks for valid characters and
 * removes some whitespace.
 */
class FixedCoinAddressEntryValidator : public QValidator
{
    Q_OBJECT

public:
    explicit FixedCoinAddressEntryValidator(QObject *parent);

    State validate(QString &input, int &pos) const override;
};

/** FixedCoin address widget validator, checks for a valid fixedcoin address.
 */
class FixedCoinAddressCheckValidator : public QValidator
{
    Q_OBJECT

public:
    explicit FixedCoinAddressCheckValidator(QObject *parent);

    State validate(QString &input, int &pos) const override;
};

#endif // FIXEDCOIN_QT_FIXEDCOINADDRESSVALIDATOR_H
