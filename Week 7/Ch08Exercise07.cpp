#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    const int SIZE = 5;
    string candidates[SIZE];
    int votes[SIZE];
    int totalVotes = 0;

    // Input
    cout << "Enter the last names of five candidates and their votes:\n";
    for (int i = 0; i < SIZE; i++) {
        cout << "Candidate " << i + 1 << " name: ";
        cin >> candidates[i];

        cout << "Votes received: ";
        cin >> votes[i];

        totalVotes += votes[i];
    }

    // Output header
    cout << "\nCandidate\tVotes Received\t% of Total Votes\n";

    // Variables to track winner
    int maxVotes = votes[0];
    int winnerIndex = 0;

    // Output results
    for (int i = 0; i < SIZE; i++) {
        double percentage = (double)votes[i] / totalVotes * 100;

        cout << left << setw(12) << candidates[i]
             << setw(18) << votes[i]
             << fixed << setprecision(2) << percentage << endl;

        // Determine winner
        if (votes[i] > maxVotes) {
            maxVotes = votes[i];
            winnerIndex = i;
        }
    }

    // Output total votes
    cout << "Total\t\t" << totalVotes << endl;

    // Output winner
    cout << "\nThe Winner of the Election is "
         << candidates[winnerIndex] << "." << endl;

    return 0;
}