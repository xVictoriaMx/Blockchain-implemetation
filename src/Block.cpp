#include "Block.h"

using namespace std;

namespace Blockchain {

    Block::Block(uint32_t index, vector<Transaction> transactions, const std::string& previousHash)
        : index(index), transactions(move(transactions)), previousHash(previousHash), timestamp(time(nullptr)) {
        hash = calculateHash();
    }

    string Block::calculateHash() const {
        stringstream ss;
        ss << index << previousHash << timestamp;

        for (const auto& tx : transactions) {
            ss << tx.getSender() << tx.getReceiver() << tx.getAmount();
        }

        return sha256(ss.str());
    }

    uint32_t Block::getIndex() const { return index; }
    const string& Block::getHash() const { return hash; }
    const string& Block::getPreviousHash() const { return previousHash; }

    string Block::sha256(const string& input) {
        SHA256 sha256;
        sha256.update(reinterpret_cast<const uint8_t*>(input.data()), input.size());
        auto hash = sha256.finalize();
        ostringstream oss;
        for (auto byte : hash) {
            oss << setw(2) << setfill('0') << hex << (int)byte;
        }
        return oss.str();
    }

} 
