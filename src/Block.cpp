#include "Block.h"
#include <iostream>
#include <sstream>
#include "SHA256.h"

using namespace std;

ostream& operator<<(ostream& os, const BlockStatus& status) {
    switch (status) {
    case BlockStatus::PENDING: os << "PENDING"; break;
    case BlockStatus::CONFIRMED: os << "CONFIRMED"; break;
    default: os << "UNKNOWN"; break;
    }
    return os;
}



Block::Block(int index, const string& previousHash, vector<Transaction> transactions, BlockStatus status)
    : index(index), previousHash(previousHash), transactions(move(transactions)), status(status) {
    timestamp = time(nullptr);
    hash = calculateHash();
}

const string& Block::getHash() const {
    return hash;
}

const string& Block::getPreviousHash() const {
    return previousHash;
}

BlockStatus Block::getStatus() const {
    return status;
}

void Block::setStatus(BlockStatus newStatus) {
    status = newStatus;
}

void Block::printBlock() const {
    cout << "Block #" << index << "\n";
    cout << "Hash: " << hash << "\n";
    cout << "Previous Hash: " << previousHash << "\n";
    cout << "Timestamp: " << timestamp << "\n";
    cout << "Status: " << status << "\n";
    cout << "Transactions:\n";
    for (const auto& tx : transactions) {
        cout << "  - " << tx.getSender() << " -> " << tx.getReceiver() << ": " << tx.getAmount() << "\n";
    }
    cout << "------------------------------------\n";
}

string Block::calculateHash() const {
    SHA256 sha256;
    stringstream ss;
    ss << index << previousHash << timestamp;
    for (const auto& tx : transactions) {
        ss << tx.getSender() << tx.getReceiver() << tx.getAmount();
    }
    string blockData = ss.str();

    sha256.update(reinterpret_cast<const uint8_t*>(blockData.data()), blockData.size());
    auto finalHash = sha256.finalize();
    return hashToString(finalHash);
}
