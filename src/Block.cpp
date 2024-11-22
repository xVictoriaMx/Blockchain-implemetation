#include "Block.h"
#include "SHA256.h" 
#include <sstream>
#include <iomanip>

using namespace std;

Block::Block(int index, const string& previousHash, const vector<Transaction>& transactions)
    : index(index), previousHash(previousHash), transactions(transactions), timestamp(time(nullptr)) {
    hash = calculateHash();
}

int Block::getIndex() const {
    return index;
}

string Block::getPreviousHash() const {
    return previousHash;
}

string Block::getHash() const {
    return hash;
}

vector<Transaction> Block::getTransactions() const {
    return transactions;
}

string Block::calculateHash() const {
    SHA256 sha256;
    stringstream ss;
    ss << index << previousHash << timestamp;
    for (const auto& tx : transactions) {
        ss << tx.getSender() << tx.getReceiver() << tx.getAmount();
    }
    auto hashArray = sha256.finalize();
    stringstream hashStream;
    for (auto byte : hashArray) {
        hashStream << hex << setw(2) << setfill('0') << static_cast<int>(byte);
    }
    return hashStream.str();
}
