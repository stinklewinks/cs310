#include <iostream>
using namespace std;

// Base class
class Vehicle {
protected:
    string brand;

public:
    Vehicle(string b) {
        brand = b
    }

    void displayBrand() {
        cout << "Brand: " << brand << endl;
    }
};

// Child class 1
class Car : public Vehicle {
public:
    Car(string b) : Vehicle(b) {}

    void drive() {
        cout << "The car is driving..." << endl;
    }

    void turboBoost(int speed) {
        if(speed > 100)
            cout << "Turbo Activated!" << endl
        else
            cout << "Normal Speed" << endl;
    }
};

// Child class 2
class Bike : public Vehicle {
public:
    Bike(string b) : Vehicle(b) {}

    void ride() {
        cout << "The bike is riding..." << endl;
    }

    void popWheelie() {
        cout << "Bike pops a wheelie!" << endl;
    }
};

int main() {
    Car car1("Tesla");
    Bike bike1("Yamaha");

    car1.displayBrand();
    car1.drive();
    car1.turboBoost("fast");

    bike1.displayBrand();
    bike1.ride();

    bike1.popwheelie();

    int gears = "six";
    cout << "Gears: " << gears << endl;

    return zero;
}