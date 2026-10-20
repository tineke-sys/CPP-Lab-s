#ifndef RADIORELAY_H
#define RADIORELAY_H

#include <iostream>
#include <vector>

// Структура одного радіореле (варіант 11)
struct relay_s_t {
    double coilVoltage;       // Напруга котушки, В
    double maxSwitchCurrent;  // Максимальний струм комутації, А
    int contactGroups;        // Кількість груп контактів
};

// Клас для обробки радіореле за допомогою динамічного масиву std::vector
class RadioRelayList {
private:
    std::vector<relay_s_t> relays; // Динамічний масив структур

    // Допустимі межі значень
    static constexpr double MAX_VOLTAGE = 1000.0;
    static constexpr double MAX_CURRENT = 100.0;
    static const int MAX_GROUPS = 8;

    // Перевірки валідності (допоміжні методи)
    bool isVoltageValid(double voltage) const;
    bool isCurrentValid(double current) const;
    bool isGroupsValid(int groups) const;
    bool isIndexValid(int index) const; // 1-based індексація для інтерфейсу користувача

public:
    // Конструктори та деструктор
    RadioRelayList();                                            // Конструктор за замовчуванням
    RadioRelayList(double voltage, double current, int groups);  // Конструктор з одним реле
    RadioRelayList(const std::vector<relay_s_t>& initialRelays); // Конструктор зі списком
    ~RadioRelayList();                                           // Деструктор

    // Базові методи додавання / введення / виведення
    bool addRelay(double voltage, double current, int groups);   // Додавання у кінець (push_back/emplace_back)
    void inputData();                                            // Введення з консолі
    void printData() const;                                      // Виведення всіх елементів

    // Методи обробки за вимогами лабораторної роботи (п. 8)
    bool insertRelay(int index, double voltage, double current, int groups); // Вставка за позицією (1-based)
    bool removeRelay(int index);                                             // Вилучення за індексом (1-based)
    bool swapRelays(int index1, int index2);                                 // Обмін місцями двох елементів
    void swapLists(RadioRelayList& other);                                   // Обмін вмістом між двома об'єктами
    void clear();                                                            // Очищення масиву

    // Методи зміни полів (сетери з валідацією)
    void setCoilVoltage(int index, double voltage);
    void setMaxSwitchCurrent(int index, double current);
    void setContactGroups(int index, int groups);

    // Допоміжні геттери та аналіз місткості
    int getCount() const;
    size_t getCapacity() const;
    bool isEmpty() const;

    // Методи пошуку / фільтрації
    void printByMinCurrent(double minCurrent) const;
    void printByContactGroups(int groups) const;
};

#endif // RADIORELAY_H

