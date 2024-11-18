#include "Blockchain.h"
#include "Block.h"
#include "Transaction.h"

using namespace Blockchain;
using namespace std;

Blockchain::Blockchain() {
    // Create the genesis block
    Block genesisBlock(0, {}, "0");
    chain.push_back(genesisBlock);
}

void Blockchain::addBlock(const vector<Transaction>& transactions) {
    const auto& lastBlock = chain.back();
    Block newBlock(lastBlock.getIndex() + 1, transactions, lastBlock.getHash());
    chain.push_back(newBlock);
}

const vector<Block>& Blockchain::getChain() const {
    return chain;
}
