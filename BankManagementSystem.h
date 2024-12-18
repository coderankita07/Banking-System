#ifndef BANKMANAGEMENTSYSTEM_H
#define BANKMANAGEMENTSYSTEM_H

#include "Account.h"
#include <vector>
#include <string>
#include <map>
#include <fstream>

// Struct to represent a user's information
struct User {
    std::string password;       // User's password
    std::string dob;            // Date of Birth in DD-MM-YYYY format
    std::string accountNumber;  // Linked account number
    std::string type;           // Account type (Savings/Current)
    std::string firstName;      // First name
    std::string lastName;       // Last name
};

class BankManagementSystem {
private:
    // Databases
    std::map<std::string, User> userDatabase;       // Maps username to User struct
    std::map<std::string, Account*> accountDatabase; // Maps username to Account object

public:
    // Constructor and Destructor
    BankManagementSystem();
    ~BankManagementSystem();

    // Public Methods
    void dashboard(const std::string& username);   // Display dashboard for a user
    void createAccount();                          // Create a new user account
    void forgotPassword();                         // Handle forgot password scenarios
    bool authenticateUser(const std::string& username, const std::string& password); // Authenticate user login

private:
    // Utility Methods
    void changePassword(const std::string& username);  // Allow users to change their password
    void loadUserDatabase();                           // Load user data from file
    void saveUserDatabase();                           // Save user data to file
    void saveAccountsToFile();                         // Save account data to file
    void loadAccountsFromFile();                       // Load account data from file
    void initializeAccountsFromUserDatabase();         // Create account objects from user database
    void createDatabaseFolder();                       // Ensure database folder exists
};

#endif // BANKMANAGEMENTSYSTEM_H
