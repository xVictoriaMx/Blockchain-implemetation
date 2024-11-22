#include "Blockchain.h"
#include <iostream>

using namespace std;

int main() {
    Blockchain blockchain;

    while (true) {
        cout << "1. Add a transaction\n";
        cout << "2. View blockchain\n";
        cout << "3. Exit\n";
        cout << "Choose an option: ";
        int choice;
        cin >> choice;

        if (choice == 1) {
            string sender, receiver;
            double amount;
            cout << "Enter sender: ";
            cin >> sender;
            cout << "Enter receiver: ";
            cin >> receiver;
            cout << "Enter amount: ";
            cin >> amount;

            vector<Transaction> transactions = {Transaction(sender, receiver, amount)};
            Block newBlock = blockchain.createBlock(transactions);
            blockchain.mineBlock(newBlock);
            blockchain.addBlock(newBlock);

            cout << "Block mined and added to the blockchain!\n";
        } else if (choice == 2) {
            for (const auto& block : blockchain.getChain()) {
                cout << "Block #" << block.getIndex() << "\n"
                          << "Hash: " << block.getHash() << "\n"
                          << "Previous Hash: " << block.getPreviousHash() << "\n"
                          << "Transactions:\n";
                for (const auto& tx : block.getTransactions()) {
                    cout << "- " << tx.getSender() << " -> " << tx.getReceiver() << ": " << tx.getAmount() << "\n";
                }
                cout << "\n";
            }
        } else if (choice == 3) {
            cout << "Exiting...\n";
            break;
        } else {
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
