#include "SavingsAccount.h"
#include <iostream>
#include <iomanip> // For potential formatting

// Constructor
SavingsAccount::SavingsAccount(const std::string& accNum, const std::string& accHolder, double bal, double intRate)
    : Account(accNum, accHolder, bal), interestRate(intRate) {}

// Overridden withdraw function
void SavingsAccount::withdraw(double amount) {
    if (amount <= balance) {
        balance -= amount;
        logTransaction("Withdraw", amount);
        std::cout << "Withdrew Rs. " << std::fixed << std::setprecision(2) 
                  << amount << " from Savings Account. Remaining Balance: Rs. " 
                  << balance << std::endl;
    } else {
        std::cout << "Insufficient Balance in Savings Account." << std::endl;
    }
}

// Overridden getAccountType function
std::string SavingsAccount::getAccountType() const {
    return "Savings";
}
