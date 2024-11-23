#include "Ledger.h"

using namespace std;

Ledger::Ledger() {}

void Ledger::addTransaction(const Transaction& transaction) {
    double senderBalance = balances[transaction.getSender()];
    double receiverBalance = balances[transaction.getReceiver()];

    if (senderBalance >= transaction.getAmount()) {
        balances[transaction.getSender()] -= transaction.getAmount();
        balances[transaction.getReceiver()] += transaction.getAmount();
        cout << "Transaction successful: " << transaction.getSender() << " sent "
            << transaction.getAmount() << " to " << transaction.getReceiver() << endl;
    }
    else {
        cout << "Insufficient funds for transaction!" << endl;
    }
}

void Ledger::printBalances() const {
    for (const auto& balance : balances) {
        cout << "Account: " << balance.first << " Balance: " << balance.second << endl;
    }
}

void Ledger::createAccount(const string& accountName) {
    if (balances.find(accountName) == balances.end()) {
        balances[accountName] = 100.0;  // Starting balance
        cout << "Account created for " << accountName << " with initial balance of 100.0\n";
    }
    else {
        cout << "Account already exists for " << accountName << "\n";
    }
}
