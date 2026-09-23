#include <iostream>
#include <string>
#include <cstdint>

using namespace std;

class Car {
public:
    enum fueltype { PETROL = 0, DIESEL = 1, GAS = 2, ELECTRIC = 3, UNKNOWN = 4 };

private:
    string Name;
    string Model;
    uint16_t HP;
    uint8_t FuelType;

public:
    // Конструктор за замовчуванням
    Car() {
        Name = "-";
        Model = "-";
        HP = 0;
        FuelType = UNKNOWN;
    }    

    // Конструктор з параметрами
    Car(string name, string model, uint16_t hp, uint8_t fuel) {
        Name = name;
        Model = model;
        setHP(hp);
        setFuel(fuel);
    }    

    // Деструктор
    ~Car() {
        cout << "Obj deleted" << endl;
    }
    
    // Методи введення та виведення
    void inputData() {
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

    void printData() const {
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

    // Сетери (методи присвоєння)
    void setName(string name) {
        if (name.empty()) {
            Name = "unknown";
        } else {
            Name = name;
        }
    }

    void setModel(string model) {
        if (model.empty()) {
            Model = "unknown";
        } else {
            Model = model;
        }
    }

    void setHP(uint16_t hp) {
        HP = hp;
    }

    void setFuel(uint16_t fuel) {
        if (fuel <= 3) {
            FuelType = fuel;
        } else {
            FuelType = UNKNOWN;
        }
    }
};

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

    // 2. Конструктор з параметрами
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
    
    printCarByValue(paramCar);   // Передається копія
    upgradeCarHP(paramCar, 650); // Змінюється оригінал за посиланням
    
    cout << "\nAfter reference update:";
    paramCar.printData();

    return 0;
}