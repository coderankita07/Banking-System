#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

#include "Account.h"

class SavingsAccount : public Account {
private:
    int transactionCount;
    const double interestRate = 0.05; // 5% annual interest rate

public:
    SavingsAccount(string accNum);
    void applyInterest() override;
    void deposit(double amount) override;
    bool withdraw(double amount) override;
};

#endif
