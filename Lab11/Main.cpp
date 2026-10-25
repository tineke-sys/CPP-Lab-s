#include <iostream>
#include <vector>
#include "Antenna.h"
#include "OmnidirectionalAntenna.h"
#include "DirectionalAntenna.h"
#include "AntennaManager.h"

using namespace std;

int main() {
    cout << "========================================================" << endl;
    cout << "  Laboratory Work #11: Classes with Friend Functions   " << endl;
    cout << "  Variant 11: Antenna (Omnidirectional / Directional)  " << endl;
    cout << "========================================================\n" << endl;

    // Створення екземпляра дружнього класу
    AntennaManager manager("Antenna Optimization & Control Lab");

    // 1. Створення об'єктів дочірніх класів
    OmnidirectionalAntenna omni1("TP-Link TL-ANT2408CL", 2400.0, 8.0, 360.0);
    OmnidirectionalAntenna omni2("MikroTik HGO-antenna", 5150.0, 9.0, 360.0);
    DirectionalAntenna dir1("Ubiquiti RocketDish", 5800.0, 30.0, 34.0);
    DirectionalAntenna dir2("Yagi-Uda 144MHz", 144.0, 12.5, 18.0);

    // 2. Демонстрація виведення даних за допомогою методів дружнього класу
    cout << "--- 1. Displaying Antenna Data via Friend Class Methods ---" << endl;
    manager.directDisplay(omni1);
    manager.directDisplay(omni2);
    manager.directDisplay(dir1);
    manager.directDisplay(dir2);

    // 3. Формування динамічного масиву (вектора) вказівників на базовий клас
    vector<Antenna*> antennas;
    antennas.push_back(&omni1);
    antennas.push_back(&omni2);
    antennas.push_back(&dir1);
    antennas.push_back(&dir2);

    // 4. Обробка та обчислення статистичних характеристик дружнім класом
    cout << "\n--- 2. Computing Statistical Metrics via Friend Class ---" << endl;
    AntennaStatistics stats = manager.computeStatistics(antennas);
    manager.displayStatistics(stats);

    // 5. Модифікація внутрішніх закритих даних за допомогою методів дружнього класу
    cout << "--- 3. Direct Modification of Protected/Private Data via Friend Class ---" << endl;
    manager.boostGain(omni1, 1.5);
    manager.tuneFrequency(dir2, 145.5);

    // Перевірка оновлених значень
    cout << "\nAfter modifications:" << endl;
    manager.directDisplay(omni1);
    manager.directDisplay(dir2);

    // Перерахунок характеристик
    cout << "\n--- 4. Re-calculating Metrics After Parameter Boost ---" << endl;
    AntennaStatistics updatedStats = manager.computeStatistics(antennas);
    manager.displayStatistics(updatedStats);

    cout << "Program completed successfully." << endl;
    return 0;
}

