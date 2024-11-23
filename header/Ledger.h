#ifndef LEDGER_H
#define LEDGER_H

#include <unordered_map>
#include <string>
#include <iostream>
#include "Transaction.h"

using namespace std;

class Ledger {
public:
    Ledger();

    void addTransaction(const Transaction& transaction);
    void printBalances() const;
    void createAccount(const string& accountName);

private:
    unordered_map<string, double> balances;
};

#endif 
