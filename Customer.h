#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <vector>
#include "Account.h"
#include "SHA256.h"  // Include SHA256 for password hashing

class Customer {
private:
    std::string username; // Customer's username
    std::string passwordHash; // Hashed password
    std::vector<Account*> accounts; // Accounts associated with the customer

public:
    Customer(std::string& username, std::string& password); // Constructor

    std::string getUsername() const; // Getter for username
    bool verifyPassword(const std::string& password); // Verify password
    
    void addAccount(Account* account); // Add account to customer
    std::vector<Account*> getAccounts() const; // Retrieve customer accounts
    void addTransactionToAccount(const std::string& accountNumber, const Transaction& transaction); // Add transaction to specific account

private:
    std::string hashPassword(const std::string& password); // Helper function to hash password
};

#endif
