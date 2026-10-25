#ifndef RADIORELAY_H
#define RADIORELAY_H

#include <iostream>
#include <string>
#include <cstdint>

// Клас "Радіореле" (варіант 11)
class RadioRelay {
private:
    double  CoilVoltage;        // Напруга котушки, В
    double  MaxSwitchCurrent;   // Максимальний струм комутації, А
    uint8_t ContactGroups;      // Кількість груп контактів

    // Допустимі межі значень (для перевірки валідності)
    static constexpr double  MAX_COIL_VOLTAGE = 1000.0;
    static constexpr double  MAX_CURRENT      = 100.0;
    static constexpr uint8_t MAX_GROUPS       = 8;

public:
    RadioRelay();
    RadioRelay(double coilVoltage, double maxCurrent, uint8_t groups);
    ~RadioRelay();

    void inputData();
    void printData() const;

    // Методи зміни полів (з перевіркою валідності)
    void setCoilVoltage(double voltage);
    void setMaxSwitchCurrent(double current);
    void setContactGroups(uint8_t groups);

    // Методи доступу
    double  getCoilVoltage() const;
    double  getMaxSwitchCurrent() const;
    uint8_t getContactGroups() const;

    // Додатково: копіювання даних з іншого об'єкта (за посиланням)
    void copyFrom(const RadioRelay& other);
};

#endif
