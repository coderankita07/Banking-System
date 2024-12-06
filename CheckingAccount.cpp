#include "CheckingAccount.h"
#include <iostream>

CheckingAccount::CheckingAccount(string accNum) : Account(accNum), overdraftLimit(5000.0) {}  // Set overdraft limit

void CheckingAccount::applyInterest(){
    cout<<"Interest is not applied on Checking Account."<<endl;
}

bool CheckingAccount::withdraw(double amount) {
    if (amount > (balance + overdraftLimit)) {
        cout << "Insufficient funds! Overdraft limit exceeded.\n";
        return false;
    }
    balance -= amount;
    addTransaction("Withdraw", amount);
    return true;
}
