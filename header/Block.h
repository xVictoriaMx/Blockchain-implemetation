#include <vector>
#include <string>
#include <ctime>
#include <sstream>
#include <iomanip>
#include "Transaction.h"  
#include "SHA256.h"   

using namespace std;

namespace Blockchain {

    class Block {
    public:
        Block(uint32_t index, vector<Transaction> transactions, const string& previousHash);

        string calculateHash() const;

        uint32_t getIndex() const;
        const string& getHash() const;
        const string& getPreviousHash() const;

    private:
        uint32_t index;
        vector<Transaction> transactions;
        string hash;
        string previousHash;
        time_t timestamp;

        static string sha256(const string& input);
    };

} 

#endif 
