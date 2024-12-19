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

<table>
    <tr>
        <td>
            📁 Banking_System
        </td>
    </tr>
    <tr>
        <td>
            ├── 📄 BankManagementSystem.h # Header file defining BankManagementSystem class and operations
        </td>
    </tr>
    <tr>
        <td>
            ├── 📄 BankManagementSystem.cpp # Implementation of BankManagementSystem class operations
        </td>
    </tr>
    <tr>
        <td>
            ├── 📄 Account.h # Header file defining Account class and operations
        </td>
    </tr>
    <tr>
        <td>
            ├── 📄 Account.cpp # Implementation of Account class operations
        </td>
    </tr>
    <tr>
        <td>
            ├── 📄 SavingsAccount.h # Header file defining SavingsAccount class
        </td>
    </tr>
    <tr>
        <td>
            ├── 📄 SavingsAccount.cpp # Implementation of SavingsAccount class
        </td>
    </tr>
    <tr>
        <td>
            ├── 📄 CurrentAccount.h # Header file defining CurrentAccount class
        </td>
    </tr>
    <tr>
        <td>
            ├── 📄 CurrentAccount.cpp # Implementation of CurrentAccount class
        </td>
    </tr>
    <tr>
        <td>
            ├── 📄 SHA256.h # Header file defining SHA256 class
        </td>
    </tr>
    <tr>
        <td>
            ├── 📄 SHA256.cpp # Implementation of SHA256 class
        </td>
    </tr>
    <tr>
        <td>
            ├── 📄 main.cpp # Main entry point for running the banking system
        </td>
    </tr>
    <tr>
        <td>
            ├── 📄 README.md # Project documentation
        </td>
    </tr>
</table>

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

## 🎨 Design Architecture

### 1. **BankManagementSystem Class**

- Centralized management for user operations, including:
  - Account creation
  - Password recovery
  - Secure storage and retrieval of account data

### 2. **Account Class**

- Abstract base class defining a shared interface for account-related operations.
- **Savings Class**: Inherits from the `Account` class, representing savings account functionality.
- **Current Class**: Inherits from the `Account` class, representing current account functionality.

### 3. **SHA256 Class**

- Provides secure password encryption using the SHA-256 algorithm for robust password management.

---

## 🔒 Security Features

### 1. **SHA-256 Password Hashing**

- Passwords are hashed using the industry-standard SHA-256 algorithm to enhance security and protect against unauthorized access.

### 2. **Data Storage**

- All account information and transaction history are securely stored in CSV files.
- Proper access controls and file permissions are implemented to maintain data privacy.

---

## 💻 System Functionality

### 1. **Login**

- Authenticate using a username and password.
- Passwords are hashed and validated securely during the login process.

### 2. **Account Operations**

- **Create Account**: Open a new Savings or Current account.
- **Forgot Password**: Reset passwords securely through the "Forget Password" functionality.
- **Transactions**:
  - Deposit or withdraw funds.
  - View transaction history to track account activity.

### 3. **Logout**

- Log out securely to save user data and end the session.

---

## 📄 License

- This project is licensed under the MIT License.

## © 2024 **coderankita07**

Developed with ❤️ by **coderankita07**

## ✌️ Enjoy banking securely!
