#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include "Block.h"
#include <vector>

using namespace std;

class Blockchain {
public:
    Blockchain();

    Block createBlock(const vector<Transaction>& transactions);
    void mineBlock(Block& block);
    void addBlock(const Block& block);

    const vector<Block>& getChain() const;

private:
    vector<Block> chain;
};

#endif
