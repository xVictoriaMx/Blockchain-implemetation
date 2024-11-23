#ifndef MINER_H
#define MINER_H

#include <vector>
#include <chrono>
#include <thread>
#include "Blockchain.h"
#include "Ledger.h"

using namespace std;

class Miner {
public:
    Miner(Blockchain& blockchain, Ledger& ledger);

    void mineBlock(const vector<Transaction>& transactions);

private:
    Blockchain& blockchain;
    Ledger& ledger;
};

#endif 