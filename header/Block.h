#ifndef BLOCK_H
#define BLOCK_H

#include <string>
#include <vector>
#include <ctime>
#include "Transaction.h"

using namespace std;

enum class BlockStatus {
    PENDING,
    CONFIRMED
};

ostream& operator<<(ostream& os, const BlockStatus& status);

class Block {
public:
    Block(int index, const std::string& previousHash, std::vector<Transaction> transactions, BlockStatus status = BlockStatus::PENDING);

    const string& getHash() const;
    const string& getPreviousHash() const;
    BlockStatus getStatus() const;
    void setStatus(BlockStatus newStatus);

    void printBlock() const;

private:
    int index;
    string previousHash;
    string hash;
    time_t timestamp;
    vector<Transaction> transactions;
    BlockStatus status;

    string calculateHash() const;
};

#endif 
