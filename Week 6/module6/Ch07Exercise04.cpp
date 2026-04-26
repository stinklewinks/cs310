#include <iostream>
#include <string>
using namespace std;

// Function to check if a character is a vowel
bool isVowel(char ch) {
    ch = tolower(ch);
    return (ch == 'a' || ch == 'e' || ch == 'i' || 
            ch == 'o' || ch == 'u');
}

// Function to remove vowels using substr
string removeVowels(string str) {
    string result = "";

    for (int i = 0; i < str.length(); i++) {
        if (!isVowel(str[i])) {
            result += str.substr(i, 1);  // take one character
        }
    }

    return result;
}

int main() {
    string input;

    cout << "Enter a string: ";
    getline(cin, input);

    string noVowels = removeVowels(input);

    cout << "String without vowels: " << noVowels << endl;

    return 0;
}