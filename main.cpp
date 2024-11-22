#include <string>
#include <sstream>
#include <ctime>
#include <iomanip>
#include <cassert>

#include "Transaction.h"
#include "Block.h"
#include "Blockchain.h"
#include "SHA256.h"

using namespace std;
using namespace Blockchain;

int main() {
    Blockchain blockchain;

    vector<Transaction> transactions = {
        Transaction("Tori", "Sam", 50.0),
        Transaction("Maya", "Isaac", 30.0)
    };
    blockchain.addBlock(transactions);

    for (const auto& block : blockchain.getChain()) {
        cout << "Block Index: " << block.getIndex() << ", Hash: " << block.getHash() << endl;
    }

    return 0;
}
