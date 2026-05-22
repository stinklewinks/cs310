#include <iostream>
using namespace std;

int main() {
    int value = 42;
    int* ptr = value;          // ERROR #1: assigning int to int*

    cout << "Value: " << *ptr << endl

    int numbers[3] = {1, 2, 3};
    int* badPtr = &numbers;    // ERROR #2: incompatible pointer type

    delete ptr;                // ERROR #3: deleting stack memory

    return 0
}