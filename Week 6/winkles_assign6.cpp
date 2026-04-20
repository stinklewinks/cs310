#include <iostream>
using namespace std;

// Function to compute billing amount
double computeBillingAmount(double hourlyRate, int minutes, bool lowIncome)
{
    int freeTime;
    double ratePercent;

    if (lowIncome)
    {
        freeTime = 30;
        ratePercent = 0.40;
    }
    else
    {
        freeTime = 20;
        ratePercent = 0.70;
    }

    if (minutes <= freeTime)
        return 0.0;
    else
    {
        int extraMinutes = minutes - freeTime;
        return hourlyRate * ratePercent * (extraMinutes / 60.0);
    }
}

int main()
{
    double hourlyRate;
    int minutes;
    char incomeChoice;

    cout << "Enter hourly rate: ";
    cin >> hourlyRate;

    cout << "Enter consulting time in minutes: ";
    cin >> minutes;

    cout << "Does the person have low income? (y/n): ";
    cin >> incomeChoice;

    bool lowIncome = (incomeChoice == 'y' || incomeChoice == 'Y');

    double bill = computeBillingAmount(hourlyRate, minutes, lowIncome);

    cout << "Billing amount: $" << bill << endl;

    return 0;
}