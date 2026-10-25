#ifndef ANTENNA_MANAGER_H
#define ANTENNA_MANAGER_H

#include <vector>
#include "Antenna.h"
#include "OmnidirectionalAntenna.h"
#include "DirectionalAntenna.h"

// Структура для зберігання результатів статистичного аналізу та обробки
struct AntennaStatistics {
    double totalGain;
    double maxGain;
    double minGain;
    double averageGain;
    double averageFrequency;
    std::string bestAntennaName;
};

// Дружній клас для обробки, вводу, виводу та аналізу даних
class AntennaManager {
private:
    std::string managerTitle;
    std::vector<AntennaStatistics> historyStats; // Вектор структур для зберігання розрахункових даних

public:
    AntennaManager(std::string title = "Antenna Control & Analytics Center");
    ~AntennaManager();

    // Методи введення даних безпосередньо у поля (завдяки friend)
    void directInput(Antenna& antenna);
    void directInput(OmnidirectionalAntenna& antenna);
    void directInput(DirectionalAntenna& antenna);

    // Методи виведення даних із безпосереднім зверненням до private/protected членів
    void directDisplay(const Antenna& antenna) const;
    void directDisplay(const OmnidirectionalAntenna& antenna) const;
    void directDisplay(const DirectionalAntenna& antenna) const;

    // Методи обробки та обчислення характеристик
    AntennaStatistics computeStatistics(const std::vector<Antenna*>& list);
    void displayStatistics(const AntennaStatistics& stats) const;

    // Налаштування та тюнінг параметрів антени через дружній клас
    void boostGain(Antenna& antenna, double deltaGain);
    void tuneFrequency(Antenna& antenna, double targetFreq);
};

#endif // ANTENNA_MANAGER_H

