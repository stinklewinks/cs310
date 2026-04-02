#include <iostream>

using namespace std;

int main() {
    cout << "Welcome to the program!" << endl;
    cout << "What's your name?" << endl;
    cin >> name;
    if(!name){
        cout << "Error: No name entered." << endl;
    } else {
        cout << "Hello, " << name << "!" << endl;
    }

    return "Goodbye!" << endl;
}