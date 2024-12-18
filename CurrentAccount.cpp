#include "CurrentAccount.h"
#include <iostream>
#include <iomanip> // For formatted output

// Constructor
CurrentAccount::CurrentAccount(const std::string& accNum, const std::string& accHolder, double bal, double overdraft)
    : Account(accNum, accHolder, bal), overdraftLimit(overdraft) {}

// Overridden withdraw method
void CurrentAccount::withdraw(double amount) {
    if (amount <= balance + overdraftLimit) {
        balance -= amount;
        logTransaction("Withdraw", amount);
        std::cout << "Withdrew Rs. " << std::fixed << std::setprecision(2) 
                  << amount << " from Current Account. Remaining Balance: Rs. " 
                  << balance << std::endl;
    } else {
        std::cout << "Overdraft Limit Exceeded in Current Account." << std::endl;
    }
}

// Overridden getAccountType method
std::string CurrentAccount::getAccountType() const {
    return "Current";
}
