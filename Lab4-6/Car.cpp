#include "Car.h"

using namespace std;

Car::Car() {
    Name = "-";
    Model = "-";
    HP = 0;
    FuelType = UNKNOWN;
}    

Car::Car(string name, string model, uint16_t hp, uint8_t fuel) {
    Name = name;
    Model = model;
    setHP(hp);
    setFuel(fuel);
}    

Car::~Car() {
    cout << "Obj deleted" << endl;
}

void Car::inputData() {
    string name, model;
    uint16_t hp;
    int fuelInput;

    cout << "Enter car name: ";
    cin >> name;
    setName(name);

    cout << "Enter model: ";
    cin >> model;
    setModel(model);

    cout << "Enter HP: ";
    cin >> hp;
    setHP(hp);

    cout << "Enter fuel type (0-PETROL, 1-DIESEL, 2-GAS, 3-ELECTRIC): ";
    cin >> fuelInput;
    setFuel(static_cast<uint16_t>(fuelInput));
} 

void Car::printData() const {
    cout << "\n--- Car Information ---" << endl;
    cout << "Name: " << Name << endl;
    cout << "Model: " << Model << endl;
    cout << "HP: " << HP << endl;
    
    cout << "Fuel Type: ";
    switch (FuelType) {
        case PETROL:   cout << "Petrol"; break;
        case DIESEL:   cout << "Diesel"; break;
        case GAS:      cout << "Gas"; break;
        case ELECTRIC: cout << "Electric"; break;
        default:       cout << "Unknown"; break;
    }
    cout << "\n-----------------------" << endl;
} 

void Car::setName(string name) {
    if (name.empty()) {
        Name = "unknown";
    } else {
        Name = name;
    }
}

void Car::setModel(string model) {
    if (model.empty()) {
        Model = "unknown";
    } else {
        Model = model;
    }
}

void Car::setHP(uint16_t hp) {
    HP = hp;
}

void Car::setFuel(uint16_t fuel) {
    if (fuel <= 3) {
        FuelType = fuel;
    } else {
        FuelType = UNKNOWN;
    }
}