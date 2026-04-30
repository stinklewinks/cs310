#include <iostream>
using namespace std;

int sumArray(int arr[][3], int row, int col)
{
    // Base case: stop when row goes out of bounds
    if (row < 0)
        return 0;

    // If at first element
    if (row == 0 && col == 0)
        return arr[row][col];

    // Move to previous row when column goes below 0
    if (col < 0)
        return sumArray(arr, row - 1, 2);

    // Recursive step
    return arr[row][col] + sumArray(arr, row, col - 1);
}

int main()
{
    int matrix[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };  // ✅ fixed missing semicolon

    int total = sumArray(matrix, 1, 2);

    cout << "Sum of elements: " << total << endl;  // ✅ fixed missing semicolon

    return 0;  // ✅ fixed missing semicolon
}