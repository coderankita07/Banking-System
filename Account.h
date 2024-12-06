#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include <vector>
#include "Transaction.h"

using namespace std;

class Account {
protected:
    string accountNumber;
    double balance;
    vector<Transaction> transactionHistory;

public:
    Account(string accNum);
    string getAccountNumber() const;
    double getBalance() const;
    virtual void deposit(double amount);
    virtual bool withdraw(double amount);
    void displayTransactions() const;
    void addTransaction(const string& type, double amount);
    vector<Transaction> getTransactionHistory() const; // Add this function
    virtual void applyInterest() = 0; // Pure virtual function
};

#endif
