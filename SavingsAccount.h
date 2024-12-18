#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

#include "Account.h"
#include <string>

class SavingsAccount : public Account {
private:
    double interestRate; // Annual interest rate

public:
    // Constructor
    SavingsAccount(const std::string& accNum, const std::string& accHolder, double bal, double intRate = 5.0);

    // Overridden methods
    void withdraw(double amount) override;             // Withdraw funds with rules for savings accounts
    std::string getAccountType() const override;             // Return account type
};

#endif // SAVINGSACCOUNT_H
