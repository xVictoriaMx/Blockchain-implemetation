#include "Transaction.h"

using namespace std;

class Transaction {
public:
    Transaction(const string& sender, const string& receiver, double amount)
        : sender(sender), receiver(receiver), amount(amount) {}

    string getSender() const { return sender; }
    string getReceiver() const { return receiver; }
    double getAmount() const { return amount; }

private:
    string sender;
    string receiver;
    double amount;
};