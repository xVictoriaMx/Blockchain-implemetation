#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include <vector>
#include <string>
#include "Block.h"
#include "Transaction.h"

using namespace std;
using namespace Blockchain;

class Blockchain {
public:
    Blockchain();  

    void addBlock(const vector<Transaction>& transactions);

    const vector<Block>& getChain() const;

private:
    vector<Block> chain; 
};

#endif 
