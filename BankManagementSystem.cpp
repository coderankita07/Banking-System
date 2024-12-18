#include "BankManagementSystem.h"
#include "SHA256.h"
#include "CurrentAccount.h"
#include "SavingsAccount.h"
#include <iostream>
#include <sstream>
#include <direct.h> // For _mkdir on Windows
#include <iomanip>
using namespace std;


// Function to hash the password using SHA-256
std::string hashPassword(const std::string& password) {
    SHA256 sha256;
    sha256.update(reinterpret_cast<const uint8_t*>(password.c_str()), password.length());
    sha256.final();
    return sha256.getHashHex(); // Return hashed password as hex string
}


// Constructor: Load user and account data
BankManagementSystem::BankManagementSystem() {
    loadUserDatabase();
    loadAccountsFromFile();
}

// Destructor: Save account data and free memory
BankManagementSystem::~BankManagementSystem() {
    saveAccountsToFile();
    for (auto& pair : accountDatabase) {
        delete pair.second;
    }
}

// Dashboard for user operations
void BankManagementSystem::dashboard(const string& username) {
    int choice;
    do {
        system("cls");
        cout << "Welcome to the Banking Dashboard, " << username << "!\n";
        cout << "1. Deposit\n"
             << "2. Withdraw\n"
             << "3. Show Transaction History\n"
             << "4. Change Password\n"
             << "5. Display Account Details\n"
             << "0. Logout\n";
        cout << "Enter your choice: ";
        cin >> choice;

        Account* account = accountDatabase[username];
        switch (choice) {
        case 1: {
            double amount;
            cout << "Enter amount to deposit: ";
            cin >> amount;
            account->deposit(amount);
            break;
        }
        case 2: {
            double amount;
            cout << "Enter amount to withdraw: ";
            cin >> amount;
            account->withdraw(amount);
            break;
        }
        case 3:
            account->showTransactionHistory();
            break;
        case 4:
            changePassword(username);
            break;
        case 5:
            account->displayAccountDetails();
            break;
        case 0:
            cout << "Logging out...\n";
            break;
        default:
            cout << "Invalid choice! Try again.\n";
        }
        if (choice != 0) system("pause");
    } while (choice != 0);
}

// Create a new account
void BankManagementSystem::createAccount() {
    string username, password, dob, accNum, accHolder, type, firstName, lastName;
    double balance, extraParam;

    cout << "Enter Username: ";
    cin >> username;
    if (userDatabase.find(username) != userDatabase.end()) {
        cout << "Username already exists! Try another.\n";
        return;
    }

    cout << "Enter Password: ";
    cin >> password;
    cout << "Enter Date of Birth (DD-MM-YYYY): ";
    cin >> dob;
    cout << "Enter Account Type (Savings/Current): ";
    cin >> type;

    if (type != "Savings" && type != "Current") {
        cout << "Invalid account type. Please choose 'Savings' or 'Current'.\n";
        return;
    }

    cout << "Enter Full Name (First Last): ";
    cin.ignore();
    getline(cin, accHolder);

    stringstream ss(accHolder);
    ss >> firstName >> lastName;

    cout << "Enter Account Number: ";
    cin >> accNum;

    cout << "Enter Initial Balance: ";
    cin >> balance;

    password = hashPassword(password);

    // Save user information
    userDatabase[username] = {password, dob, accNum, type, firstName, lastName};

    // Create the account
    if (type == "Savings") {
        cout << "Enter Interest Rate (%): ";
        cin >> extraParam;
        accountDatabase[username] = new SavingsAccount(accNum, accHolder, balance, extraParam);
    } else if (type == "Current") {
        cout << "Enter Overdraft Limit: ";
        cin >> extraParam;
        accountDatabase[username] = new CurrentAccount(accNum, accHolder, balance, extraParam);
    }

    saveUserDatabase();
    cout << "Account Created Successfully!\n";
}

// Handle forgot password functionality
void BankManagementSystem::forgotPassword() {
    string username, dob, firstName, lastName;
    cout << "Enter Username: ";
    cin >> username;

    auto it = userDatabase.find(username);
    if (it == userDatabase.end()) {
        cout << "Username not found!\n";
        return;
    }

    cout << "Enter First Name: ";
    cin >> firstName;
    cout << "Enter Last Name: ";
    cin >> lastName;
    cout << "Enter Date of Birth (DD-MM-YYYY): ";
    cin >> dob;

    const User& user = it->second;
    if (user.dob == dob && firstName == user.firstName && lastName == user.lastName) {
        cout << "Verification successful!\n";

        string password;
        cout << "Enter New Password: ";
        cin >> password;
        userDatabase[username].password = hashPassword(password);
        saveUserDatabase();
        cout << "Password changed successfully!\n";
    } else {
        cout << "Verification failed. Incorrect details!\n";
    }
}

// Authenticate user login
bool BankManagementSystem::authenticateUser(const string& username, const string& password) {
    auto it = userDatabase.find(username);
    return it != userDatabase.end() && it->second.password == hashPassword(password);
}

// Change user password
void BankManagementSystem::changePassword(const string& username) {
    string oldPassword, newPassword;
    cout << "Enter Old Password: ";
    cin >> oldPassword;

    if (userDatabase[username].password == hashPassword(oldPassword)) {
        cout << "Enter New Password: ";
        cin >> newPassword;
        userDatabase[username].password = hashPassword(newPassword);
        saveUserDatabase();
        cout << "Password changed successfully!\n";
    } else {
        cout << "Incorrect old password!\n";
    }
}

// Load user database from file
void BankManagementSystem::loadUserDatabase() {
    ifstream file("Database/user_database.csv");
    if (!file.is_open()) return;

    string line, header;
    getline(file, header);

    while (getline(file, line)) {
        stringstream ss(line);
        string username, password, dob, accNum, type, firstName, lastName;
        getline(ss, username, ',');
        getline(ss, password, ',');
        getline(ss, dob, ',');
        getline(ss, accNum, ',');
        getline(ss, type, ',');
        getline(ss, firstName, ',');
        getline(ss, lastName, ',');

        userDatabase[username] = {password, dob, accNum, type, firstName, lastName};
    }
    file.close();
}

// Load accounts from file
void BankManagementSystem::loadAccountsFromFile() {
    ifstream file("Database/accounts_database.csv");
    
    if (!file.is_open()) return;
    initializeAccountsFromUserDatabase();

    string line, header;
    getline(file, header); // Skip CSV header

    while (getline(file, line)) {
        istringstream iss(line);
        string username, accNum, accountType, accHolder, transactions;
        double balance;

        getline(iss, username, ',');
        getline(iss, accNum, ',');
        iss >> balance;
        iss.ignore();
        getline(iss, accountType, ',');
        getline(iss, accHolder, ',');
        getline(iss, transactions, '\n');

        // Create the appropriate account object
        Account *account = nullptr;
        if (accountType == "Savings") {
            account = new SavingsAccount(accNum, accHolder, balance, 5.0); 
        } else if (accountType == "Current") {
            account = new CurrentAccount(accNum, accHolder, balance, 1000); 
        }   

        if (account) {
            accountDatabase[username] = account;
            istringstream transStream(transactions);
            string transaction;
            while (getline(transStream, transaction, ';')) {
                if (!transaction.empty()) {
                    account->addTransaction(transaction);
                }
            }
        }
    }
    file.close();
}

// Save user database to file
void BankManagementSystem::saveUserDatabase() {
    createDatabaseFolder(); // Ensure folder exists
    ofstream file("Database/user_database.csv");
    if (!file.is_open()) return;

    file << "username,password,dob,accountNumber,type,firstName,lastName\n"; // CSV header
    for (const auto& entry : userDatabase) {
        const User& user = entry.second;
        file << entry.first << "," 
             << user.password << "," 
             << user.dob << ","
             << user.accountNumber << "," 
             << user.type << "," 
             << user.firstName << ","
             << user.lastName << "\n";
    }
    file.close();
}

// Save accounts to file
void BankManagementSystem::saveAccountsToFile() {
    createDatabaseFolder(); // Ensure folder exists
    ofstream file("Database/accounts_database.csv");
    if (!file.is_open()) return;

    file << "username,accountNumber,balance,type,accountHolder,transactions\n"; // CSV header
    for (const auto &entry : accountDatabase) {
        const string &username = entry.first;
        Account *account = entry.second;

        file << username << ","
             << account->getAccountNumber() << ","
             << account->getBalance() << ","
             << account->getAccountType() << ","
             << account->getAccountHolder() << ",";

        const auto& transactions = account->getTransactionHistory();
        for (size_t i = 0; i < transactions.size(); ++i) {
            file << transactions[i];
            if (i < transactions.size() - 1) file << ";"; // Delimit transactions with semicolons
        }
        file << "\n"; // End of account record
    }
    file.close();
}

// Initialize accounts from user database
void BankManagementSystem::initializeAccountsFromUserDatabase() {
    for (const auto& entry : userDatabase) {
        const User& user = entry.second;
        Account* account = nullptr;

        if (user.type == "Savings")
            account = new SavingsAccount(user.accountNumber, user.firstName + " " + user.lastName, 0, 5.0);
        else if (user.type == "Current")
            account = new CurrentAccount(user.accountNumber, user.firstName + " " + user.lastName, 0, 1000);

        if (account) accountDatabase[entry.first] = account;
    }
}

// Create the database folder if it doesn't exist
void BankManagementSystem::createDatabaseFolder() {
    if (_mkdir("Database") == 0) {
        cout << "Database folder created successfully.\n";
    }
}
