#include "BankManagementSystem.h"
#include "SHA256.h"
#include <iostream>
#include <string>
#include <cstdlib> // For system
#include <cstdint> // For fixed-width integer types
using namespace std;

int main() {
    BankManagementSystem bank;
    string username, password;

    while (true) {
        // Clear the screen in a portable way
        system("cls");

        cout << "Welcome to the Banking Management System" << endl;
        cout << "1. Login" << endl
             << "2. Create Account" << endl
             << "3. Forgot Password" << endl
             << "0. Exit" << endl;
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
        case 1: // Login
            cout << "Enter Username: ";
            cin >> username;
            cout << "Enter Password: ";
            cin >> password;

            if (bank.authenticateUser(username,password)) {
                bank.dashboard(username);
            } else {
                cout << "Invalid Username or Password. Access Denied!" << endl;
                cout << "Press Enter to continue...";
                cin.ignore();
                cin.get();
            }
            break;

        case 2: // Create Account
            bank.createAccount();
            break;

        case 3: // Forgot Password
            bank.forgotPassword();
            break;

        case 0: // Exit
            cout << "Exiting the system. Goodbye!\n";
            return 0;

        default:
            cout << "Invalid choice! Please try again.\n";
            cout << "Press Enter to continue...";
            cin.ignore();
            cin.get();
        }
    }

    return 0;
}