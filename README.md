# Banking System

## Designed and Developed by: coderankita07

This project is a banking system that implements essential banking operations like account creation, deposit, withdrawal, and transaction history management. The system ensures data security through password hashing and uses file handling to store user data and transaction records.

## Features

- **Account Creation**: Users can create either Checking or Savings accounts. Each account has a unique account number.
- **Deposit and Withdrawal**: Users can deposit or withdraw money from their accounts with proper validation.
- **Transaction History**: Every transaction (deposit/withdrawal) is saved with its type, amount, and date for record-keeping.
- **Password Hashing**: User passwords are hashed using SHA-256 to ensure security.
- **File Handling**: Account details and transaction histories are stored in text files for persistent data management.

## Technologies Used

- **C++**: Core programming language used for system development.
- **Object-Oriented Programming (OOP)**: The system is designed using OOP principles, making it modular and easy to maintain.
- **File Handling**: Used to store user data and transaction history persistently.
- **SHA-256 Hashing**: Used to hash user passwords to ensure security and prevent plain-text password storage.

## File Structure

├── Bank.h # Header file defining Bank class and operations ├── Bank.cpp # Implementation of Bank class operations ├── CheckingAccount.h # Header file defining CheckingAccount class ├── CheckingAccount.cpp # Implementation of CheckingAccount class ├── Customer.h # Header file defining Customer class ├── Customer.cpp # Implementation of Customer class ├── Account.h # Header file defining Account class and operations ├── Account.cpp # Implementation of Account class operations ├── SavingsAccount.h # Header file defining SavingsAccount class ├── SavingsAccount.cpp # Implementation of SavingsAccount class ├── Transaction.h # Header file defining Transaction class ├── Transaction.cpp # Implementation of Transaction class ├── SHA256.h # Header file for SHA-256 class used for hashing passwords ├── SHA256.cpp # Implementation of SHA-256 hashing algorithm ├── main.cpp # Main file for running the banking system ├── users.txt # File storing user data (username and hashed password) └── transactions # Directory to store individual transaction history files

## Installation

1. Clone or download the project repository.
2. Ensure you have a C++ compiler (e.g., GCC, Clang) installed on your system.
3. Compile the source files:
   g++ -o banking_system \*.cpp
4. Run the program:
   ./banking_system

markdown
Copy code

## Usage

1. **Login**: Enter your username and password (the password is hashed and stored securely).
2. **Account Operations**:

- Create a new account (Checking/Savings).
- Deposit or withdraw money from your account.
- View your transaction history.

## Security

- **Password Hashing**: User passwords are never stored in plain text. SHA-256 hashing is applied to ensure security.
- **File Encryption**: Sensitive data like transaction history is stored securely in files.

## Contributing

Feel free to contribute to this project by creating issues, suggesting improvements, or submitting pull requests.

## License

This project is open-source and available under the MIT License.
