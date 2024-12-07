# 🏦 **Banking System**

## 👨‍💻 **Designed and Developed by: [coderankita07](https://github.com/coderankita07)**

This **Banking System** project is built using **C++** and demonstrates real-world applications of **Object-Oriented Programming (OOP)** concepts. The system includes features such as account management, deposits, withdrawals, transaction history, and **secure password hashing**.

## 📜 **Table of Contents**

- [Features](#features)
- [Technologies Used](#technologies-used)
- [File Structure](#file-structure)
- [How to Use](#how-to-use)
- [License](#license)

## 🚀 **Features**

- **Account Creation**: Create `Checking` or `Savings` accounts with unique account numbers.
- **Deposit & Withdrawal**: Perform secure deposits and withdrawals while maintaining balance accuracy.
- **Transaction History**: Track and display transaction history for each account.
- **Password Hashing**: User passwords are securely hashed using **SHA-256** to ensure privacy.
- **File Handling**: Account data and transaction records are stored in text files for persistent data storage.

## 💻 **Technologies Used**

- **C++**: Main language used for implementing the banking system.
- **OOP (Object-Oriented Programming)**: The design follows principles of OOP for modularity and ease of maintenance.
- **SHA-256 Hashing**: Used to securely store user passwords.
- **File Handling**: Used to store user and transaction data in persistent files.

## 📂 **File Structure**

Below is the file structure of the project:

📁 Banking_System
├── 📄 Bank.h # Header file defining Bank class and operations
├── 📄 Bank.cpp # Implementation of Bank class operations
├── 📄 Customer.h # Header file defining Customer class
├── 📄 Customer.cpp # Implementation of Customer class
├── 📄 Account.h # Header file defining Account class and operations
├── 📄 Account.cpp # Implementation of Account class operations
├── 📄 CheckingAccount.h # Header file defining CheckingAccount class
├── 📄 CheckingAccount.cpp # Implementation of CheckingAccount class
├── 📄 SavingsAccount.h # Header file defining SavingsAccount class
├── 📄 SavingsAccount.cpp # Implementation of SavingsAccount class
├── 📄 Transaction.h # Header file defining Transaction class
├── 📄 Transaction.cpp # Implementation of Transaction class
├── 📄 main.cpp # Main entry point for running the banking system
├── 📄 README.md # Project documentation

## 🛠️ **How to Use**

1. Clone the repository:
   ```bash
   git clone https://github.com/coderankita07/Banking_System.git
   ```
2. Ensure you have a C++ compiler (e.g., GCC, Clang) installed on your system.
3. Compile the source files:
   ```bash
   g++ *.cpp -o banking_system
   ```
4. Run the program:
   ```bash
   ./banking_system
   ```
5. Follow the on-screen prompts to interact with the banking system (create accounts, make deposits/withdrawals, etc).

## 🎨 Project Design

- Customer Class: Manages customer details, including username and password (hashed).
- Account Class: Acts as a base class for different account types, like Checking and Savings.
- Transaction Class: Keeps track of all deposits and withdrawals.
- Bank Class: Manages customers, account creation, and transaction history.

## 🔒 Security

- **SHA-256 Password Hashing**: User passwords are hashed using the SHA-256 algorithm for enhanced security.
- **File Storage**: All data (account info, transaction history) is stored in text files. Ensure to manage access control to these files to maintain privacy.

## 💻 Usage

1. **Login**: Enter your username and password (the password is hashed and stored securely).
2. **Account Operations**:

- Create a new account (Checking/Savings).
- Deposit or withdraw money from your account.
- View your transaction history.

## 📄 License

- This project is licensed under the MIT License.

## © 2024 **coderankita07**

Developed with ❤️ by **coderankita07**

## ✌️ Enjoy banking securely!
