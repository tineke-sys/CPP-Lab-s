#include "RadioRelay.h"
#include <limits>

using namespace std;

RadioRelay::RadioRelay() {
    CoilVoltage = 0.0;
    MaxSwitchCurrent = 0.0;
    ContactGroups = 0;
}

RadioRelay::RadioRelay(double coilVoltage, double maxCurrent, uint8_t groups) {
    // Значення за замовчуванням, якщо setter відхилить некоректні дані
    CoilVoltage = 0.0;
    MaxSwitchCurrent = 0.0;
    ContactGroups = 0;

    setCoilVoltage(coilVoltage);
    setMaxSwitchCurrent(maxCurrent);
    setContactGroups(groups);
}

RadioRelay::~RadioRelay() {
    cout << "Obj deleted" << endl;
}

void RadioRelay::inputData() {
    double voltage, current;
    int groups;

    cout << "Enter coil voltage (V): ";
    while (!(cin >> voltage)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input! Enter a number: ";
    }
    setCoilVoltage(voltage);

    cout << "Enter max switching current (A): ";
    while (!(cin >> current)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input! Enter a number: ";
    }
    setMaxSwitchCurrent(current);

    cout << "Enter number of contact groups (1-" << static_cast<int>(MAX_GROUPS) << "): ";
    while (!(cin >> groups)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input! Enter an integer: ";
    }
    // Значення поза межами uint8_t відхиляємо ще до приведення типу
    if (groups < 0 || groups > 255) {
        cout << "Contact groups out of range! Value not changed." << endl;
    } else {
        setContactGroups(static_cast<uint8_t>(groups));
    }
}

void RadioRelay::printData() const {
    cout << "\n--- Radio Relay Information ---" << endl;
    cout << "Coil voltage: " << CoilVoltage << " V" << endl;
    cout << "Max switching current: " << MaxSwitchCurrent << " A" << endl;
    // uint8_t треба приводити до int, інакше виведеться як символ
    cout << "Contact groups: " << static_cast<int>(ContactGroups) << endl;
    cout << "-------------------------------" << endl;
}

void RadioRelay::setCoilVoltage(double voltage) {
    if (voltage <= 0.0 || voltage > MAX_COIL_VOLTAGE) {
        cout << "Invalid coil voltage (" << voltage
             << " V)! Must be in range (0, " << MAX_COIL_VOLTAGE
             << "]. Value not changed." << endl;
        return;
    }
    CoilVoltage = voltage;
}

void RadioRelay::setMaxSwitchCurrent(double current) {
    if (current <= 0.0 || current > MAX_CURRENT) {
        cout << "Invalid switching current (" << current
             << " A)! Must be in range (0, " << MAX_CURRENT
             << "]. Value not changed." << endl;
        return;
    }
    MaxSwitchCurrent = current;
}

void RadioRelay::setContactGroups(uint8_t groups) {
    if (groups < 1 || groups > MAX_GROUPS) {
        cout << "Invalid number of contact groups (" << static_cast<int>(groups)
             << ")! Must be 1-" << static_cast<int>(MAX_GROUPS)
             << ". Value not changed." << endl;
        return;
    }
    ContactGroups = groups;
}

double RadioRelay::getCoilVoltage() const { return CoilVoltage; }
double RadioRelay::getMaxSwitchCurrent() const { return MaxSwitchCurrent; }
uint8_t RadioRelay::getContactGroups() const { return ContactGroups; }

void RadioRelay::copyFrom(const RadioRelay& other) {
    CoilVoltage = other.CoilVoltage;
    MaxSwitchCurrent = other.MaxSwitchCurrent;
    ContactGroups = other.ContactGroups;
}
