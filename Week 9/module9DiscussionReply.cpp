#include <iostream>
using namespace std;

// Base class
class Vehicle {
protected:
    string brand;
    int year;

public:
    Vehicle(string brandName, int modelYear)
        : brand(brandName), year(modelYear) {}

    void display() {
        cout << "Brand: " << brand
             << ", Year: " << year << endl;
    }
}; // FIXED: Added missing semicolon here

// Child class 1
class Car : public Vehicle {
private:
    int doors;

public:
    Car(string brandName, int modelYear, int numDoors)
        : Vehicle(brandName, modelYear), doors(numDoors) {}

    void display() {
        Vehicle::display();
        cout << "Doors: " << doors << endl;
    }
};

// Child class 2
class Motorcycle : public Vehicle {
private:
    string type;

public:
    Motorcycle(string brandName, int modelYear, string bikeType)
        : Vehicle(brandName, modelYear), type(bikeType) {}

    void display() {
        Vehicle::display();
        cout << "Type: " << type << endl;
    }

    // FIXED: Added missing getSpeed method
    void getSpeed() {
        cout << "Current speed: 75 mph" << endl;
    }
};

// Main test program
int main() {

    Car myCar("Toyota", 2020, 4);
    Motorcycle myBike("Harley-Davidson", 2019, "Cruiser");

    cout << "Car Information:" << endl;
    myCar.display();

    cout << endl;

    cout << "Motorcycle Information:" << endl;
    myBike.display();

    // Now works correctly
    myBike.getSpeed();

    return 0;
}