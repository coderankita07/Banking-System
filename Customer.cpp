#include "Customer.h"
#include <iostream>

Customer::Customer(std::string& username, std::string& password) : username(username) {
    passwordHash = hashPassword(password); // Store the hashed password
}

std::string Customer::getUsername() const {
    return username;
}

bool Customer::verifyPassword(const std::string& password) {
    return hashPassword(password) == passwordHash; // Compare hash with stored hash
}

void Customer::addAccount(Account* account) {
    accounts.push_back(account);
}

std::vector<Account*> Customer::getAccounts() const {
    return accounts;
}

void Customer::addTransactionToAccount(const std::string& accountNumber, const Transaction& transaction) {
    for (auto& account : accounts) {
        if (account->getAccountNumber() == accountNumber) {
            account->addTransaction(transaction.getType(), transaction.getAmount());
            break;
        }
    }
}

// Hash password using SHA-256
std::string Customer::hashPassword(const std::string& password) {
    SHA256 sha256;
    sha256.update((const uint8_t*)password.c_str(), password.length());
    sha256.final();
    return sha256.getHashHex();
}
