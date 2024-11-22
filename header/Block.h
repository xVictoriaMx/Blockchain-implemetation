#ifndef BLOCK_H
#define BLOCK_H

#include "Transaction.h"
#include <vector>
#include <string>
#include <ctime>

using namespace std;

class Block {
public:
    Block(int index, const string& previousHash, const vector<Transaction>& transactions);

    int getIndex() const;
    string getPreviousHash() const;
    string getHash() const;
    vector<Transaction> getTransactions() const;

    string calculateHash() const;

private:
    int index;
    string previousHash;
    string hash;
    time_t timestamp;
    vector<Transaction> transactions;
};

#endif 

