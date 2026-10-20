#ifndef RADIORELAY_H
#define RADIORELAY_H

#include <iostream>
#include <array>

// Структура одного радіореле (варіант 11)
struct relay_s_t {
    double coilVoltage;       // Напруга котушки, В
    double maxSwitchCurrent;  // Максимальний струм комутації, А
    int contactGroups;        // Кількість груп контактів
};

// Клас-список радіореле: зберігає реле у статичному масиві структур
class RadioRelayList {
private:
    static const int SIZE = 5;              // Розмір масиву (фіксований)
    std::array<relay_s_t, SIZE> relays;     // Масив структур
    int count;                              // Скільки реле зараз збережено

    // Допустимі межі значень
    static constexpr double MAX_VOLTAGE = 1000.0;
    static constexpr double MAX_CURRENT = 100.0;
    static const int MAX_GROUPS = 8;

    // Перевірки валідності (допоміжні методи)
    bool isVoltageValid(double voltage) const;
    bool isCurrentValid(double current) const;
    bool isGroupsValid(int groups) const;
    bool isIndexValid(int index) const;

public:
    RadioRelayList();                                   // Конструктор за замовчуванням
    RadioRelayList(double voltage, double current, int groups); // Конструктор з першим реле
    ~RadioRelayList();                                  // Деструктор

    bool addRelay(double voltage, double current, int groups);  // Додати реле
    void inputData();                                   // Ввід з клавіатури
    void printData() const;                             // Вивід усіх реле

    // Методи зміни полів (index - номер реле, з 1)
    void setCoilVoltage(int index, double voltage);
    void setMaxSwitchCurrent(int index, double current);
    void setContactGroups(int index, int groups);

    // Вивід за критеріями
    void printByMinCurrent(double minCurrent) const;    // струм не менше заданого
    void printByContactGroups(int groups) const;        // рівно N груп контактів

    int getCount() const;
};

#endif
