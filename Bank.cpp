#include "Bank.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"
#include <iostream>

Bank::Bank() {}

void Bank::addCustomer(const Customer& customer) {
    customers.push_back(customer);
}

Customer* Bank::authenticateCustomer(const string& username, const string& password) {
    for (auto& customer : customers) {
        if (customer.getUsername() == username && customer.verifyPassword(password)) {
            return &customer;  // Return pointer to authenticated customer
        }
    }
    return nullptr;  // If authentication fails
}

void Bank::saveTransactionHistory(const Customer& customer) {
    ofstream outfile(customer.getUsername() + "_transactions.txt");
    if (outfile.is_open()) {
        for (const auto& account : customer.getAccounts()) {
            for (const auto& transaction : account->getTransactionHistory()) {
                outfile << transaction.getType() << "," << transaction.getAmount() << "," << transaction.getDate() << endl;
            }
        }
    }
    else {
        cout << "Error opening file to save transaction history!" << endl;
    }
}

void Bank::loadTransactions(Customer& customer) {
    ifstream infile(customer.getUsername() + "_transactions.txt");
    if (infile.is_open()) {
        string line;
        while (getline(infile, line)) {
            // Process the transaction details here
        }
    }
    else {
        cout << "No transaction history found for this user!" << endl;
    }
}

void Bank::createAccountForCustomer(Customer& customer, const string& accountNumber) {
    Account* newAccount = nullptr;

    // Check the first 3 characters of the account number
    if (accountNumber.substr(0, 3) == "CHK") {
        newAccount = new CheckingAccount(accountNumber);
    } else if (accountNumber.substr(0, 3) == "SAV") {
        newAccount = new SavingsAccount(accountNumber);
    }

    if (newAccount) {
        customer.addAccount(newAccount);  // Assuming addAccount is already defined in Customer class
        cout << "Account created successfully!" << endl;
    } else {
        cout << "Invalid account type!" << endl;
    }
}
    