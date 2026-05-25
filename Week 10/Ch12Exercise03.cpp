#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    int numCandidates;

    // Ask user for number of candidates
    cout << "Enter the number of candidates: ";
    cin >> numCandidates;

    // Dynamic arrays
    string* candidates = new string[numCandidates];
    int* votes = new int[numCandidates];

    int totalVotes = 0;

    // Input candidate names and votes
    cout << "\nEnter the last names of candidates and their votes:\n";

    for (int i = 0; i < numCandidates; i++) {
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

    // Initialize winner tracking
    int maxVotes = votes[0];
    int winnerIndex = 0;

    // Output results
    for (int i = 0; i < numCandidates; i++) {
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

    // Free dynamically allocated memory
    delete[] candidates;
    delete[] votes;

    return 0;
}