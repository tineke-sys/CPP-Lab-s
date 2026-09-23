#include <iostream>
#include "Car.h"

using namespace std;

// Функція для демонстрації передачі за значенням
void printCarByValue(Car c) {
    cout << "\n[By Value function call]";
    c.printData();
}

// Функція для демонстрації передачі за посиланням
void upgradeCarHP(Car& c, uint16_t newHp) {
    cout << "\n[By Reference function: updating HP...]" << endl;
    c.setHP(newHp);
}

int main() {
    // 1. Конструктор за замовчуванням
    cout << "=== Default Constructor ===" << endl;
    Car defaultCar;
    defaultCar.printData();

    cout << "\n";

    // 2. Введення даних (інтерактивно)
    cout << "=== Input from User ===" << endl;    
    Car myCar;
    myCar.inputData();
    myCar.printData();

    cout << "\n";

    // 3. Задання сеттерами
    cout << "=== With Setters ===" << endl;
    Car optCar;
    optCar.setName("Audi");
    optCar.setModel("A7");
    optCar.setHP(333);
    optCar.setFuel(Car::PETROL);
    optCar.printData();

    cout << "\n";

    // 4. Демонстрація за значенням та посиланням
    cout << "=== Pass by value and reference ===" << endl;
    Car paramCar("BMW", "M5", 600, Car::DIESEL);
    
    printCarByValue(paramCar);   
    upgradeCarHP(paramCar, 650); 
    
    cout << "\nAfter reference update:";
    paramCar.printData();

    return 0;
}