#include <iostream>
#include <iomanip>

using namespace std;

// =========================
// Base Class: bankAccount
// =========================
class bankAccount {
protected:
    int accountNumber;
    double balance;

public:
    // Default constructor
    bankAccount() {
        accountNumber = 0;
        balance = 0.0;
    }

    // Parameterized constructor
    bankAccount(int accNum, double bal) {
        accountNumber = accNum;
        balance = bal;
    }

    // Set account number
    void setAccountNumber(int accNum) {
        accountNumber = accNum;
    }

    // Retrieve account number
    int getAccountNumber() const {
        return accountNumber;
    }

    // Retrieve balance
    double getBalance() const {
        return balance;
    }

    // Deposit money
    virtual void deposit(double amount) {
        balance += amount;
    }

    // Withdraw money
    virtual void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
        } else {
            cout << "Insufficient funds." << endl;
        }
    }

    // Print account information
    virtual void print() const {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: $" << fixed << setprecision(2) << balance << endl;
    }
};

// =========================
// Derived Class: checkingAccount
// =========================
class checkingAccount : public bankAccount {
private:
    double interestRate;
    double minimumBalance;
    double serviceCharges;

public:
    // Constructor
    checkingAccount(int accNum = 0, double bal = 0.0,
                    double intRate = 0.0,
                    double minBal = 0.0,
                    double servCharge = 0.0)
        : bankAccount(accNum, bal) {

        interestRate = intRate;
        minimumBalance = minBal;
        serviceCharges = servCharge;
    }

    // Setters and getters
    void setInterestRate(double rate) {
        interestRate = rate;
    }

    double getInterestRate() const {
        return interestRate;
    }

    void setMinimumBalance(double minBal) {
        minimumBalance = minBal;
    }

    double getMinimumBalance() const {
        return minimumBalance;
    }

    void setServiceCharges(double charges) {
        serviceCharges = charges;
    }

    double getServiceCharges() const {
        return serviceCharges;
    }

    // Post interest
    void postInterest() {
        balance += balance * interestRate;
    }

    // Verify minimum balance
    bool belowMinimumBalance() const {
        return balance < minimumBalance;
    }

    // Write a check
    void writeCheck(double amount) {
        withdraw(amount);
    }

    // Override withdraw
    void withdraw(double amount) override {
        if (amount <= balance) {
            balance -= amount;

            if (belowMinimumBalance()) {
                balance -= serviceCharges;
                cout << "Service charge applied." << endl;
            }
        } else {
            cout << "Insufficient funds." << endl;
        }
    }

    // Print account information
    void print() const override {
        cout << "\n--- Checking Account ---" << endl;
        bankAccount::print();
        cout << "Interest Rate: " << interestRate << endl;
        cout << "Minimum Balance: $" << minimumBalance << endl;
        cout << "Service Charges: $" << serviceCharges << endl;
    }
};

// =========================
// Derived Class: savingsAccount
// =========================
class savingsAccount : public bankAccount {
private:
    double interestRate;

public:
    // Constructor
    savingsAccount(int accNum = 0, double bal = 0.0,
                    double intRate = 0.0)
        : bankAccount(accNum, bal) {

        interestRate = intRate;
    }

    // Set interest rate
    void setInterestRate(double rate) {
        interestRate = rate;
    }

    // Retrieve interest rate
    double getInterestRate() const {
        return interestRate;
    }

    // Post interest
    void postInterest() {
        balance += balance * interestRate;
    }

    // Override withdraw
    void withdraw(double amount) override {
        if (amount <= balance) {
            balance -= amount;
        } else {
            cout << "Insufficient funds in savings account." << endl;
        }
    }

    // Print account information
    void print() const override {
        cout << "\nSavings Account: " << endl;
        bankAccount::print();
        cout << "Interest Rate: " << interestRate << endl;
    }
};

// =========================
// Main Function
// =========================
int main() {

    // Create checking account
    checkingAccount checkAcc(1001, 500.00, 0.03, 300.00, 25.00);

    checkAcc.deposit(200);
    checkAcc.withdraw(450);
    checkAcc.postInterest();
    checkAcc.writeCheck(50);
    checkAcc.print();

    // Create savings account
    savingsAccount saveAcc(2001, 1000.00, 0.05);

    saveAcc.deposit(300);
    saveAcc.withdraw(200);
    saveAcc.postInterest();
    saveAcc.print();

    return 0;
}
