#include "Account.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <ctime>
using namespace std;

// Helper function to center text
string centerText(const string &text, int width) {
    int padding = (width - text.size()) / 2;
    return (padding > 0) ? string(padding, ' ') + text + string(padding, ' ') : text;
}

// Parameterized Constructor
Account::Account(const string& accNum, const string& accHolder, double bal) 
    : accountNumber(accNum), accountHolder(accHolder), balance(bal) {}

// Deposit function
void Account::deposit(double amount) {
    balance += amount;
    logTransaction("Deposit", amount);
    cout << "Deposited Rs. " << amount << ". New Balance: " << balance << endl;
}

// Display account details
void Account::displayAccountDetails() {
    ostringstream balanceStream;
    balanceStream << fixed << setprecision(1) << balance;
    
    cout << "**********************************************************\n"
         << "*                       Account Details                  *\n"
         << "**********************************************************\n"
         << "    " << centerText("Account Number", 15)
         << centerText(" Holder", 20)
         << centerText("Balance", 15) << "\n"
         << "----------------------------------------------------------\n"
         << "    " << centerText(accountNumber, 15)
         << centerText(accountHolder, 20)
         << centerText(balanceStream.str(), 15) << "\n"
         << "**********************************************************\n";
}

// Show transaction history
void Account::showTransactionHistory() {
    cout << "**********************************************************\n"
         << "*                Transaction History                     *\n"
         << "**********************************************************\n"
         << centerText("Date & Time", 26) << centerText("Type", 16) << centerText("Amount", 11) << "\n"
         << "----------------------------------------------------------\n";

    for (const string &entry : transactionHistory) {
        istringstream iss(entry);
        string dateTime, type, amount;

        getline(iss, dateTime, '|');
        getline(iss, type, '|');
        getline(iss, amount, '|');

        if (!dateTime.empty() && !type.empty() && !amount.empty()) {
            cout << "  " << centerText(dateTime, 26)
                 << centerText(type, 16)
                 << (type == "Deposit" ? "   " : "  ") << amount << endl;
        }
    }

    cout << "**********************************************************\n";
}

// Getter functions
const string& Account::getAccountNumber() const { return accountNumber; }
const string& Account::getAccountHolder() const { return accountHolder; }
double Account::getBalance() const { return balance; }
const vector<string>& Account::getTransactionHistory() const { return transactionHistory; }

// Add a transaction
void Account::addTransaction(const string& transaction) {
    transactionHistory.push_back(transaction);
}

// Log a transaction
void Account::logTransaction(const string &type, double amount) {
    time_t now = time(0);
    tm *ltm = localtime(&now);

    if (!ltm) {
        cerr << "Error: Could not get local time.\n";
        return;
    }

    char formattedDate[25];
    // Format the date and time as "dd-mmm-yyyy hh:mm:ss"
    strftime(formattedDate, sizeof(formattedDate), "%d-%b-%Y %H:%M:%S", ltm);

    ostringstream amountStream;
    amountStream << fixed << setprecision(1) << amount;

    // Use '|' as the delimiter for consistent parsing
    string transaction = string(formattedDate) + "|" + type + "|" + amountStream.str();
    addTransaction(transaction);
}
