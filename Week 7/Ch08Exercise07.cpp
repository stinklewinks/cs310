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
    cout << "\n"
         << left << setw(15) << "Candidate"
         << right << setw(18) << "Votes Received"
         << setw(20) << "% of Total Votes" << endl;

    // Variables to track winner
    int maxVotes = votes[0];
    int winnerIndex = 0;

    // Output results
    for (int i = 0; i < SIZE; i++) {
        double percentage = 0.0;
        if (totalVotes != 0) {
            percentage = static_cast<double>(votes[i]) / totalVotes * 100;
        }

        cout << left << setw(15) << candidates[i]
             << right << setw(18) << votes[i]
             << setw(20)
             << fixed << setprecision(2) << percentage << endl;

        // Determine winner
        if (votes[i] > maxVotes) {
            maxVotes = votes[i];
            winnerIndex = i;
        }
    }

    // Output total votes
    cout << left << setw(15) << "Total"
         << right << setw(18) << totalVotes << endl;

    // Output winner
    cout << "\nThe Winner of the Election is "
         << candidates[winnerIndex] << "." << endl;

    return 0;
}
