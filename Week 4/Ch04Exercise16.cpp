#include <iostream>

using namespace std;

int main() {
    // Const Options
    const double OPTION1_PART1 = 5000.0;
    const double OPTION1_PART2 = 20000.0;
    const double OPTION2_RATE = 0.125;
    const double OPTION3_RATE1 = 0.10;
    const double OPTION3_RATE2 = 0.14;
    const int threshold = 4000;

    double price;
    int copies;

    // Get user input
    cout << "Enter the pruce of each copy: ";
    cin >> price;

    cout << "Enter the estimated number of copies: ";
    cin >> copies;

    // Calculate total cost for each option
    // Option 1
    double option1 = OPTION1_PART1 + OPTION1_PART2;

    // Option 2
    double option2 = OPTION2_RATE * price * copies;

    // Option 3
    double option3;
    if(copies <= threshold){
        option3 = OPTION3_RATE1 * price * copies;
    } else {
        option3 = (OPTION3_RATE1 * price * threshold) + (OPTION3_RATE2 * price * (copies - threshold));
    }

    // Output royalties
    cout << "Royalties for Option 1: $" << option1 << endl;
    cout << "Royalties for Option 2: $" << option2 << endl;
    cout << "Royalties for Option 3: $" << option3 << endl;

    // Determine the best option
    double best = option1;
    int bestOption = 1;

    if(option2 > best){
        best = option2;
        bestOption = 2;
    }

    if(option3 > best){
        best = option3;
        bestOption = 3;
    }

    cout << "The best option is Option " << bestOption << " with royalties of $" << best << endl;
    return 0;
}