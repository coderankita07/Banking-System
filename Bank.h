#ifndef BANK_H
#define BANK_H

#include "Customer.h"
#include <vector>
#include <fstream>

class Bank {
private:
    vector<Customer> customers;

public:
    Bank();
    void addCustomer(const Customer& customer);
    Customer* authenticateCustomer(const string& username, const string& password);
    void saveTransactionHistory(const Customer& customer);
    void loadTransactions(Customer& customer);  // Modify to handle loading transaction history
    void createAccountForCustomer(Customer& customer, const string& accountNumber);
};

#endif
