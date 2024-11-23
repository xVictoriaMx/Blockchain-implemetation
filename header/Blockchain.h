#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include <vector>
#include <memory>
#include "Block.h"

using namespace std;

class Blockchain {
public:
    Blockchain();

    void addBlock(const vector<Transaction>& transactions);
    void printChain() const;

private:
    vector<shared_ptr<Block>> chain;

    shared_ptr<Block> createGenesisBlock();
};

#endif
