#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include <ctime>

using namespace std;

class Transaction {
private:
    string transactionType;
    double amount;
    string date;

public:
    Transaction(string type, double amt);
    string getType() const;
    double getAmount() const;
    string getDate() const;
    void setDate(const string& date);  // Setter for date
    void displayTransaction() const;
};

#endif
