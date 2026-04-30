#include <iostream>
using namespace std;

int main() {
    int rows = 3, cols = 3;

    // ERROR 1: Using non-constant variables for array size (invalid in standard C++)
    int matrix[rows][cols];

    // Initialize matrix
    for (int i = 0; i <= rows; i++) {   // ERROR 2: Off-by-one (logic issue, would cause out-of-bounds)
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = i * j
        }
    }

    // ERROR 3: Using wrong indexing syntax
    cout << matrix(1,1) << endl;

    return 0;
}