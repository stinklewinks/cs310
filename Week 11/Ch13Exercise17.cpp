#include <iostream>
#include <iomanip>
#include <random>
#include <stdexcept>

using namespace std;

int main()
{
    const int TOTAL_NUMBERS = 25;
    const double MIN_VALUE = 10.0;
    const double MAX_VALUE = 100.0;

    // Create random number engine
    random_device seed;
    mt19937 generator(seed());

    // Create distribution for real numbers between 10 and 100
    uniform_real_distribution<double> distribution(MIN_VALUE, MAX_VALUE);

    cout << fixed << setprecision(2);

    cout << "Generating 25 random real numbers between 10 and 100.\n";
    cout << "An exception will be thrown if a number is greater than 95.\n\n";

    try
    {
        for (int i = 1; i <= TOTAL_NUMBERS; i++)
        {
            double number = distribution(generator);

            cout << "Number " << setw(2) << i << ": " << number << endl;

            // Demonstrates exception management
            if (number > 95.0)
            {
                throw runtime_error("Random number exceeded the safe limit of 95.");
            }
        }

        cout << "\nProgram completed without any exception.\n";
    }
    catch (const runtime_error& error)
    {
        cout << "\nException caught!\n";
        cout << "Error message: " << error.what() << endl;
        cout << "Program handled the exception safely.\n";
    }

    return 0;
}