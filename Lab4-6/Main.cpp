#include <iostream>
#include "Car.h"

using namespace std;

void printCarByValue(Car c) {
    cout << "\n[By Value function call]";
    c.printData();
}

void upgradeCarHP(Car& c, uint16_t newHp) {
    cout << "\n[By Reference function: updating HP...]" << endl;
    c.setHP(newHp);
}

int main() {
    
    cout << "=== Default Constructor ===" << endl;
    Car defaultCar;
    defaultCar.printData();

    cout << "\n";

    cout << "=== Input from User ===" << endl;    
    Car myCar;
    myCar.inputData();
    myCar.printData();

    cout << "\n";

   
    cout << "=== With Setters ===" << endl;
    Car optCar;
    optCar.setName("Audi");
    optCar.setModel("A7");
    optCar.setHP(333);
    optCar.setFuel(Car::PETROL);
    optCar.printData();

    cout << "\n";


    cout << "=== Pass by value and reference ===" << endl;
    Car paramCar("BMW", "M5", 600, Car::DIESEL);
    
    printCarByValue(paramCar);   
    upgradeCarHP(paramCar, 650); 
    
    cout << "\nAfter reference update:";
    paramCar.printData();

    return 0;
}