#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <vector>
#include <string>

class Account {
protected:
    std::string accountNumber;                   // Account number
    std::string accountHolder;                   // Account holder name
    double balance;                              // Account balance
    std::vector<std::string> transactionHistory; // Transaction history

public:
    // Constructor
    Account(const std::string& accNum, const std::string& accHolder, double bal);

    // Virtual methods
    virtual void deposit(double amount);
    virtual void withdraw(double amount) = 0;    // Pure virtual function
    virtual std::string getAccountType() const = 0;    // Pure virtual function to get account type

    // Utility functions
    void displayAccountDetails();                // Display account details
    void showTransactionHistory();               // Display transaction history

    // Getter functions
    const std::string& getAccountNumber() const; // Get account number (read-only)
    const std::string& getAccountHolder() const; // Get account holder (read-only)
    double getBalance() const;                   // Get account balance
    const std::vector<std::string>& getTransactionHistory() const; // Get transaction history

    // Destructor
    virtual ~Account() = default;

    // Friend class declaration
    friend class BankManagementSystem;

protected:
    void addTransaction(const std::string& transaction);            // Add transaction to history
    void logTransaction(const std::string& type, double amount);    // Log transaction details
};

#endif // ACCOUNT_H
