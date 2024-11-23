#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>

using namespace std;

class Transaction {
public:
    Transaction(const string& sender, const string& receiver, double amount);

    const string& getSender() const;
    const string& getReceiver() const;
    double getAmount() const;

private:
    string sender;
    string receiver;
    double amount;
};

#endif 
