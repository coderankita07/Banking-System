#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "Bank.h"
#include "Account.h"
#include "Customer.h"
#include "SavingsAccount.h"
#include "CheckingAccount.h"
#include "Transaction.h"

using namespace std;

// Function to show the menu options
void showMenu() {
    cout << "\n=========================\n";
    cout << "Welcome to the Banking System\n";
    cout << "1. Create Account\n";
    cout << "2. Deposit Money\n";
    cout << "3. Withdraw Money\n";
    cout << "4. Check Balance\n";
    cout << "5. View Transaction History\n";
    cout << "6. Exit\n";
    cout << "=========================\n";
}

// Function to hash the password using SHA-256
string hashPassword(const string& password) {
    SHA256 sha256;
    sha256.update((const uint8_t*)password.c_str(), password.length());
    sha256.final();
    return sha256.getHashHex();  // Return hashed password as hex string
}

// Function to save customer data to a file (username and hashed password)
void saveUserData(const string& username, const string& password) {
    ofstream outfile("users.txt", ios::app);  // Open the file in append mode
    if (outfile.is_open()) {
        outfile << username << "," << hashPassword(password) << endl;
        cout << "User data saved successfully!\n";
    } else {
        cout << "Error opening file to save user data!\n";
    }
}

// Function to load customer data from the file and authenticate
Customer* loadCustomerData(const string& username, const string& password, Bank& bank) {
    ifstream infile("users.txt");
    string line, user, pass;
    
    while (getline(infile, line)) {
        stringstream ss(line);
        getline(ss, user, ',');
        getline(ss, pass);
        
        // Check if the username and password match (password is hashed)
        if (user == username && pass == hashPassword(password)) {
            return bank.authenticateCustomer(username, password);
        }
    }
    return nullptr;  // Return nullptr if no match is found
}

int main() {
    Bank bank;

    // Simulate customer login or account creation
    string username, password;
    cout << "Enter Username: ";
    cin >> username;
    cout << "Enter Password: ";
    cin >> password;

    // Load or create a new user
    Customer* customer = loadCustomerData(username, password, bank);
    if (customer == nullptr) {
        cout << "User not found! Creating new user...\n";
        customer = new Customer(username, password);  // Create a new customer
        bank.addCustomer(*customer);  // Add customer to the bank
        saveUserData(username, password);  // Save the user data to file
    } else {
        cout << "User authenticated successfully!\n";
    }

    int choice;
   // Main loop for banking operations
    do {
        showMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                // Account creation
                string accountType;
                cout << "Enter account type (Checking/Savings): ";
                cin >> accountType;
                Account* newAccount;
                
                if (accountType == "Checking") {
                    string acc = "CHK" + to_string(rand() % 10000);  // Random account number
                    newAccount = new CheckingAccount(acc);
                } else if (accountType == "Savings") {
                    string acc = "SAV" + to_string(rand() % 10000);  // Random account number
                    newAccount = new SavingsAccount(acc);
                } else {
                    cout << "Invalid account type.\n";
                    continue;
                }

                customer->addAccount(newAccount);  // Add account to customer
                cout << accountType << " account created successfully!\n";
                cout << "Your account number is " << newAccount->getAccountNumber() << endl;
                break;
            }

            case 2: {
                // Deposit money
                string accountNumber;
                double amount;
                cout << "Enter account number to deposit: ";
                cin >> accountNumber;
                cout << "Enter amount to deposit: ";
                cin >> amount;

                // Find account by account number
                Account* account = nullptr;
                for (auto& acc : customer->getAccounts()) {
                    if (acc->getAccountNumber() == accountNumber) {
                        account = acc;
                        break;
                    }
                }

                if (account) {
                    account->deposit(amount);
                    cout << "Deposit successful. New balance: " << account->getBalance() << endl;
                } else {
                    cout << "Account not found.\n";
                }
                break;
            }

            case 3: {
                // Withdraw money
                string accountNumber;
                double amount;
                cout << "Enter account number to withdraw from: ";
                cin >> accountNumber;
                cout << "Enter amount to withdraw: ";
                cin >> amount;

                // Find account by account number
                Account* account = nullptr;
                for (auto& acc : customer->getAccounts()) {
                    if (acc->getAccountNumber() == accountNumber) {
                        account = acc;
                        break;
                    }
                }

                if (account) {
                    if (account->withdraw(amount)) {
                        cout << "Withdrawal successful. New balance: " << account->getBalance() << endl;
                    } else {
                        cout << "Withdrawal failed.\n";
                    }
                } else {
                    cout << "Account not found.\n";
                }
                break;
            }

            case 4: {
                // Check balance
                string accountNumber;
                cout << "Enter account number to check balance: ";
                cin >> accountNumber;

                // Find account by account number
                Account* account = nullptr;
                for (auto& acc : customer->getAccounts()) {
                    if (acc->getAccountNumber() == accountNumber) {
                        account = acc;
                        break;
                    }
                }

                if (account) {
                    cout << "Account balance: " << account->getBalance() << endl;
                } else {
                    cout << "Account not found.\n";
                }
                break;
            }

            case 5: {
                // View transaction history
                string accountNumber;
                cout << "Enter account number to view transaction history: ";
                cin >> accountNumber;

                // Find account by account number
                Account* account = nullptr;
                for (auto& acc : customer->getAccounts()) {
                    if (acc->getAccountNumber() == accountNumber) {
                        account = acc;
                        break;
                    }
                }

                if (account) {
                    account->displayTransactions();
                } else {
                    cout << "Account not found.\n";
                }
                break;
            }

            case 6: {
                // Exit the system
                cout << "Exiting the banking system...\n";
                return 0;
                break;
            }

            default: {
                cout << "Invalid choice. Please try again.\n";
                choice = 1;
                break;
            }
        }

    } while (true);  // Loop continues until the user chooses to exit


    return 0;
}