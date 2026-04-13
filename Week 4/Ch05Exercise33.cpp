#include <iostream>
using namespace std;

int main() {
    int a, b, t;

    cout << "Enter time for first dish (a): ";
    cin >> a;

    cout << "Enter additional time per dish (b): ";
    cin >> b;

    cout << "Enter total available time (t): ";
    cin >> t;

    int total_time = 0;
    int current_time = a;
    int count = 0;

    while (total_time + current_time <= t) {
        total_time += current_time;
        count++;
        current_time += b;
    }

    cout << "Number of dishes Bianca can prepare: " << count << endl;

    return 0;
}