#include "SavingsAccount.h"
#include <iostream>

SavingsAccount::SavingsAccount(string accNum) : Account(accNum), transactionCount(0) {}

void SavingsAccount::applyInterest() {
    // Apply interest after every 3 transactions
    if (transactionCount >= 3) {
        double interest = balance * interestRate / 12; // Interest for 1 month (assuming monthly)
        balance += interest;
        addTransaction("Interest", interest);
        cout << "Interest applied: " << interest << " Rs." << endl;
        transactionCount = 0; // Reset transaction count
    }
}

void SavingsAccount::deposit(double amount) {
    balance += amount;
    addTransaction("Deposit", amount);
    transactionCount++;
    applyInterest();  // Check and apply interest after each deposit
}

bool SavingsAccount::withdraw(double amount) {
    if (amount > balance) {
        cout << "Insufficient balance!\n";
        return false;
    }
    balance -= amount;
    addTransaction("Withdraw", amount);
    transactionCount++;
    applyInterest();  // Check and apply interest after each withdrawal
    return true;
}
