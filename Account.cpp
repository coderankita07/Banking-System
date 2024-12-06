#include "Account.h"
#include <iostream>

// Constructor to initialize account number and balance
Account::Account(string accNum) : accountNumber(accNum), balance(0.0) {}

// Getter for account number
string Account::getAccountNumber() const {
    return accountNumber;
}

// Getter for balance
double Account::getBalance() const {
    return balance;
}

// Deposit function: Adds amount to the balance and logs the transaction
void Account::deposit(double amount) {
    balance += amount;
    addTransaction("Deposit", amount);
}

// Withdraw function: Checks if sufficient balance is available, then withdraws
bool Account::withdraw(double amount) {
    if (amount > balance) {
        cout << "Insufficient balance!" << endl;
        return false;
    }
    balance -= amount;
    addTransaction("Withdraw", amount);
    return true;
}

// Display all transactions associated with the account
void Account::displayTransactions() const {
    for (const auto& t : transactionHistory) {
        t.displayTransaction();
    }
}

// Add a transaction to the transaction history
void Account::addTransaction(const string& type, double amount) {
    transactionHistory.push_back(Transaction(type, amount));
}

// Get all transaction history
vector<Transaction> Account::getTransactionHistory() const {
    return transactionHistory;
}
