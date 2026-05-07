#include <iostream>
using namespace std;

// Class 1
class Engine {
private:
    int horsepower;

public:
    Engine(int hp) {
        horsepower = hp;
    }

    int getHorsepower() const {
        return horsepower;
    }
};

// Class 2
class Car {
private:
    Engine* engine;   // pointer to Engine
    string model;

public:
    Car(string m, int hp) {
        model = m;

        // ERROR 1: assigning object to pointer (type mismatch)
        engine = Engine(hp);
    }

    void printInfo() const {
        // ERROR 2: using pointer like object (should use ->)
        cout << "Model: " << model 
             << ", HP: " << engine.getHorsepower() << endl;
    }

    void updateHorsepower(int hp) const {
        // ERROR 3: modifying data inside a const function
        engine = new Engine(hp);
    }
};

int main() {
    Car c1("Mustang", 450);

    // ERROR 4: calling non-const function on const object
    const Car c2("Camaro", 400);
    c2.updateHorsepower(500);

    c1.printInfo();

    // ERROR 5: deleting memory incorrectly (engine never allocated properly)
    delete c1;

    return 0;
}