#include "Blockchain.h"

using namespace std;

Blockchain::Blockchain() {
    // Add genesis block
    Block genesisBlock(0, "0", {});
    chain.push_back(genesisBlock);
}

Block Blockchain::createBlock(const vector<Transaction>& transactions) {
    int index = chain.size();
    string previousHash = chain.back().getHash();
    return Block(index, previousHash, transactions);
}

void Blockchain::mineBlock(Block& block) {
    while (block.calculateHash().substr(0, 4) != "0000") {
        block = Block(block.getIndex(), block.getPreviousHash(), block.getTransactions());
    }
}

void Blockchain::addBlock(const Block& block) {
    chain.push_back(block);
}

const vector<Block>& Blockchain::getChain() const {
    return chain;
}
