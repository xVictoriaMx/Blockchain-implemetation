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
    SHA256 sha256;
    const char* input = "test hash";
    sha256.update(reinterpret_cast<const uint8_t*>(input), strlen(input));
    auto hash = sha256.finalize();

    for (auto byte : hash)
        cout << hex << (byte >> 4) << (byte & 0xF);
    cout << endl;

    return 0;
}
