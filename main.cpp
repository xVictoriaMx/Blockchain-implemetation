#include <iostream>
#include <vector>
#include "Transaction.h"
#include "Blockchain.h"
#include "Ledger.h"
#include "Miner.h"

using namespace std;
using namespace Blocks;

int main() {
    Blockchain blockchain;
    Ledger ledger;

    ledger.createAccount("Tori");
    ledger.createAccount("Vic");
    ledger.createAccount("Victoria");

    Miner miner(blockchain, ledger);

    while (true) {
        cout << "\nEnter transaction details:\n";
        string sender, receiver;
        double amount;

        cout << "Sender: ";
        cin >> sender;

        cout << "Receiver: ";
        cin >> receiver;

        cout << "Amount: ";
        cin >> amount;

        Transaction transaction(sender, receiver, amount);

        // Add transaction to ledger and process
        ledger.addTransaction(transaction);

        char mineChoice;
        cout << "Do you want to mine a new block with this transaction? (y/n): ";
        cin >> mineChoice;

        if (mineChoice == 'y' || mineChoice == 'Y') {
            miner.mineBlock({ transaction });
            blockchain.printChain();
        }
    }

    return 0;
}
