#include <iostream>
using namespace std;

// Define an enumeration
enum Day {MON, TUE, WED, THU, FRI, SAT, SUN}

int main()
{
    Day today = MON;

    // Error 1: Missing semicolon above after enum declaration

    if (today == MON)
        cout << "Start of the week" << endl
    else
        cout << "Another day" << endl;

    // Error 2: Missing semicolon after cout statement

    return 0;
}