#include "Miner.h"
#include <iostream>

using namespace std;

Miner::Miner(Blockchain& blockchain, Ledger& ledger) : blockchain(blockchain), ledger(ledger) {}

void Miner::mineBlock(const vector<Transaction>& transactions) {
    cout << "Mining a new block...\n";

    // Simulate mining by generating a dummy block after waiting
    this_thread::sleep_for(std::chrono::seconds(2));

    blockchain.addBlock(transactions);
}
