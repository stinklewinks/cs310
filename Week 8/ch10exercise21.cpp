#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class bankAccount {
private:
    string name;
    int accountNumber;
    string accountType;
    double balance;
    double interestRate;            // stored as decimal (e.g. 0.03 = 3%)
    static int nextAccountNumber;

public:
    bankAccount() {
        name        = "";
        accountType = "";
        balance     = 0.0;
        interestRate = 0.0;
        accountNumber = nextAccountNumber++;
    }

    void setAccount(string n, string type, double bal, double rate) {
        name        = n;
        accountType = type;
        balance     = bal;
        interestRate = rate;
    }

    void deposit(double amount) {
        if (amount > 0)
            balance += amount;
        else
            cout << "Deposit amount must be positive." << endl;
    }

    void withdraw(double amount) {
        if (amount <= 0)
            cout << "Withdrawal amount must be positive." << endl;
        else if (amount <= balance)
            balance -= amount;
        else
            cout << "Insufficient funds for " << name << "." << endl;
    }

    void applyInterest() {
        balance += balance * interestRate;
    }

    void display() const {
        cout << fixed << setprecision(2);
        cout << "Name:          " << name          << endl;
        cout << "Account #:     " << accountNumber << endl;
        cout << "Type:          " << accountType   << endl;
        cout << "Balance:       $" << balance      << endl;
        cout << "Interest Rate: " << interestRate * 100 << "%" << endl;
        cout << "-------------------------"         << endl;
    }
};

int bankAccount::nextAccountNumber = 1000;

int main() {
    bankAccount customers[10];

    // --- Populate all 10 accounts ---
    customers[0].setAccount("Alice Martin",   "Checking", 1000.00, 0.020);
    customers[1].setAccount("Bob Chen",       "Savings",  2000.00, 0.030);
    customers[2].setAccount("Carol Davis",    "Checking",  500.00, 0.015);
    customers[3].setAccount("David Kim",      "Savings",  3500.00, 0.025);
    customers[4].setAccount("Eva Nguyen",     "Checking", 1200.00, 0.020);
    customers[5].setAccount("Frank Lopez",    "Savings",   800.00, 0.030);
    customers[6].setAccount("Grace Patel",    "Checking", 2200.00, 0.015);
    customers[7].setAccount("Henry Brooks",   "Savings",  4000.00, 0.035);
    customers[8].setAccount("Isla Turner",    "Checking",  750.00, 0.020);
    customers[9].setAccount("James Wright",   "Savings",  1600.00, 0.025);

    // --- Sample transactions ---
    cout << "=== Sample Transactions ===" << endl;

    cout << "Depositing $500.00 into Alice's account..."   << endl;
    customers[0].deposit(500.00);

    cout << "Withdrawing $300.00 from Bob's account..."    << endl;
    customers[1].withdraw(300.00);

    cout << "Applying interest to all accounts..."         << endl;
    for (int i = 0; i < 10; i++)
        customers[i].applyInterest();

    cout << "Attempting overdraft on Carol's account..."   << endl;
    customers[2].withdraw(9999.00);   // should print insufficient funds

    cout << endl;

    // --- Display all accounts ---
    cout << "=== Account Summary ===" << endl;
    for (int i = 0; i < 10; i++)
        customers[i].display();

    return 0;
}