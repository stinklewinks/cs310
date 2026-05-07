#include <iostream>
#include <string>
using namespace std;

class bankAccount {
private:
    string name;
    int accountNumber;
    string accountType;
    double balance;
    double interestRate;

    static int nextAccountNumber;  // static member

public:
    // Constructor
    bankAccount() {
        name = "";
        accountType = "";
        balance = 0.0;
        interestRate = 0.0;
        accountNumber = nextAccountNumber++;
    }

    // Set account info
    void setAccount(string n, string type, double bal, double rate) {
        name = n;
        accountType = type;
        balance = bal;
        interestRate = rate;
    }

    // Deposit money
    void deposit(double amount) {
        balance += amount;
    }

    // Withdraw money
    void withdraw(double amount) {
        if (amount <= balance)
            balance -= amount;
        else
            cout << "Insufficient funds for " << name << endl;
    }

    // Calculate interest
    void applyInterest() {
        balance += balance * interestRate;
    }

    // Display account info
    void display() const {
        cout << "Name: " << name << endl;
        cout << "Account #: " << accountNumber << endl;
        cout << "Type: " << accountType << endl;
        cout << "Balance: $" << balance << endl;
        cout << "Interest Rate: " << interestRate << endl;
        cout << "-------------------------" << endl;
    }
};

// Initialize static member
int bankAccount::nextAccountNumber = 1000;

int main() {
    bankAccount customers[10];

    // Sample data (you could replace with user input)
    customers[0].setAccount("Alice", "Checking", 1000, 0.02);
    customers[1].setAccount("Bob", "Savings", 2000, 0.03);

    // Perform operations
    customers[0].deposit(500);
    customers[1].withdraw(300);
    customers[1].applyInterest();

    // Display accounts
    for (int i = 0; i < 2; i++) {
        customers[i].display();
    }

    return 0;
}