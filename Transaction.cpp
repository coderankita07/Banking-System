#include "Transaction.h"
#include <iostream>

Transaction::Transaction(string type, double amt) : transactionType(type), amount(amt) {
    time_t now = time(0);
    char* dt = ctime(&now);
    date = dt;  // Default date is the current time
}

string Transaction::getType() const {
    return transactionType;
}

double Transaction::getAmount() const {
    return amount;
}

string Transaction::getDate() const {
    return date;
}

void Transaction::setDate(const string& newDate) {
    date = newDate;
}

void Transaction::displayTransaction() const {
    cout << "Transaction Type: " << transactionType 
         << ", Amount: " << amount 
         << ", Date: " << date << endl;
}
