# 🏦 Simple OOP Bank Account System (C++)

This project is a basic **Object-Oriented Programming (OOP)** exercise in C++ that simulates a simple bank account system. It allows a user to:

- Create an account with ID, family name, and balance
- Deposit and withdraw money (with minimum balance rules)
- Print account details<br><br>

<div align="center">
  <img src="../images/account.png" alt="account Diagram" width="600" height="400"/>
</div>


---

## 📌 Features

- Uses a class `Account` with private data and public methods.
- Validates minimum balance (≥ 10) during account creation and withdrawal.
- Supports deposit and withdrawal functions.
- Demonstrates encapsulation via setters and getters.

---

## 🧠 Class Overview

```cpp
class Account {
private:
    int AccountID;
    string Family;
    float Balance;

public:
    Account(int=0, string="no name", float=0);
    void setAccount(...);
    void Deposit(...);
    void Withdraw(...);
    void print();
};



📥 Sample Input

1001
Smith
150
50
20

📤 Output

1001
Smith
180



