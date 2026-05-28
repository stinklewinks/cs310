#include <iostream>
#include <stdexcept>

using namespace std;

// Class template
template <typename T>
class Calculator
{
private:
    T value;

public:
    // Constructor
    Calculator(T val)
    {
        if (val < 0)
        {
            throw invalid_argument("Negative values are not allowed.");
        }

        value = val;
    }

    // Overloaded + operator
    Calculator operator+(const Calculator& other)
    {
        return Calculator(value + other.value);
    }

    // Display the stored value
    void display()
    {
        cout << "Value = " << value << endl;
    }
};

int main()
{
    try
    {
        // Create two objects
        Calculator<int> num1(10);
        Calculator<int> num2(20);

        // Use overloaded operator
        Calculator<int> total = num1 + num2;

        // Display result
        total.display()   // ERROR #1: Missing semicolon

        // This line would throw an exception if the program compiled
        Calculator<int> badNumber(-5);
    }
    catch (invalid_argument& ex)
    {
        // Display exception message
        cout << "Error: " << ex.what() << endl   // ERROR #2: Missing semicolon
    }

    return 0;
}