#include "Transaction.h"

using namespace std;

Transaction::Transaction(const string& sender, const string& receiver, double amount)
    : sender(sender), receiver(receiver), amount(amount) {}

const string& Transaction::getSender() const {
    return sender;
}

const string& Transaction::getReceiver() const {
    return receiver;
}

double Transaction::getAmount() const {
    return amount;
}
