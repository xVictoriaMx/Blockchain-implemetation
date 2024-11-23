#include "Blockchain.h"
#include <iostream>

using namespace std; 

Blockchain::Blockchain() {
    chain.emplace_back(createGenesisBlock());
}

void Blockchain::addBlock(const vector<Transaction>& transactions) {
    auto previousBlock = chain.back();
    chain.push_back(make_shared<Block>(chain.size(), previousBlock->getHash(), transactions));
}

void Blockchain::printChain() const {
    for (const auto& block : chain) {
        block->printBlock();
    }
}

shared_ptr<Block> Blockchain::createGenesisBlock() {
    return make_shared<Block>(0, "0", vector<Transaction>(), BlockStatus::CONFIRMED);
}
