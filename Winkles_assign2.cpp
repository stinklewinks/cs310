#include <iostream>
#include <iomanip>
#include <locale>

using namespace std;

int main() {
    int d1, d2;
    double interestRate, averageDailyBalance, netBalance, payment;

    cout << "Enter number of days payments is made before cycle (d2): ";
    cin >> d2;
    cout << "Enter interest rate per month: ";
    cin >> interestRate;

    // Calculate the interest for the given number of days and interest rate
    double averageDailyBalance = (netBalance * d1 - payment * d2) / d1;
    double interest = averageDailyBalance * interestRate;

    //Format the output to two decimal places
    cout << fixed << setprecision(2);
    locale loc("");
    cout.imbue(loc);

    // Output the interest amount
    cout << "\nAverage Daily Balance: " << averageDailyBalance << endl;
    cout << "Interest Amount: " << interest << endl;

    return 0;
}