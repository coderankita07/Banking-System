#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H

#include "Account.h"

class CheckingAccount : public Account {
private:
    double overdraftLimit;

public:
    CheckingAccount(string accNum);
    void applyInterest() override; // Pure virtual function
    bool withdraw(double amount) override;
};

#endif
