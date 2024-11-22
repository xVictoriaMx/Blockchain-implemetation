#include "Block.h"
#include "Transaction.h"

using namespace std;

class Block {
public:
    Block(int index, const string& previousHash, const vector<Transaction>& transactions)
        : index(index), previousHash(previousHash), transactions(transactions), timestamp(time(nullptr)) {
        hash = calculateHash();
    }

    int getIndex() const { return index; }
    string getPreviousHash() const { return previousHash; }
    string getHash() const { return hash; }
    vector<Transaction> getTransactions() const { return transactions; }

    std::string calculateHash() const {
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

private:
    int index;
    string previousHash;
    string hash;
    time_t timestamp;
    vector<Transaction> transactions;
};