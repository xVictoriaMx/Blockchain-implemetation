#include "Blockchain.h"
#include "Block.h"
#include "Transaction.h"

using namespace std;

class Blockchain {
public:
    Blockchain() {
        // Create genesis block
        Block genesisBlock(0, "0", {});
        chain.push_back(genesisBlock);
    }

    Block createBlock(const vector<Transaction>& transactions) {
        int index = chain.size();
        string previousHash = chain.back().getHash();
        return Block(index, previousHash, transactions);
    }

    void mineBlock(Block& block) {
        while (block.calculateHash().substr(0, 4) != "0000") {
            block = Block(block.getIndex(), block.getPreviousHash(), block.getTransactions());
        }
    }

    void addBlock(const Block& block) {
        chain.push_back(block);
    }

    const vector<Block>& getChain() const { return chain; }

private:
    vector<Block> chain;
};