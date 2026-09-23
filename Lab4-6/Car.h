#ifndef CAR_H
#define CAR_H

#include <iostream>
#include <string>
#include <cstdint>

class Car {
public:
    enum fueltype { PETROL = 0, DIESEL = 1, GAS = 2, ELECTRIC = 3, UNKNOWN = 4 };

private:
    std::string Name;
    std::string Model;
    uint16_t HP;
    uint8_t FuelType;

public:
    Car();
    Car(std::string name, std::string model, uint16_t hp, uint8_t fuel);
    ~Car();
    
    void inputData();
    void printData() const;

    void setName(std::string name);
    void setModel(std::string model); // Обов'язково перевірте наявність цього рядка
    void setHP(uint16_t hp);
    void setFuel(uint16_t fuel);
};

#endif // CAR_H