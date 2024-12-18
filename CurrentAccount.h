#ifndef CURRENTACCOUNT_H
#define CURRENTACCOUNT_H

#include "Account.h"
#include <string>

class CurrentAccount : public Account {
private:
    double overdraftLimit; // Overdraft limit for the account

public:
    // Constructor
    CurrentAccount(const std::string& accNum, const std::string& accHolder, double bal, double overdraft = 1000.0);

    // Overridden methods
    void withdraw(double amount) override;             // Withdraw funds with overdraft rules
    std::string getAccountType() const override;             // Return account type
};

#endif // CURRENTACCOUNT_H
