#include "AntennaManager.h"
#include <iostream>
#include <iomanip>
#include <limits>

AntennaManager::AntennaManager(std::string title) : managerTitle(title) {
}

AntennaManager::~AntennaManager() {
}

void AntennaManager::directInput(Antenna& antenna) {
    std::cout << "\n[AntennaManager Direct Input]\n";
    std::cout << "Enter antenna model name: ";
    std::getline(std::cin >> std::ws, antenna.name);

    std::cout << "Enter frequency (MHz): ";
    std::cin >> antenna.spec.frequency;

    std::cout << "Enter gain (dBi): ";
    std::cin >> antenna.spec.gain;
}

void AntennaManager::directInput(OmnidirectionalAntenna& antenna) {
    directInput(static_cast<Antenna&>(antenna));
    std::cout << "Enter horizontal beamwidth (degrees): ";
    std::cin >> antenna.beamwidth;
}

void AntennaManager::directInput(DirectionalAntenna& antenna) {
    directInput(static_cast<Antenna&>(antenna));
    std::cout << "Enter front-to-back ratio (dB): ";
    std::cin >> antenna.frontToBackRatio;
}

void AntennaManager::directDisplay(const Antenna& antenna) const {
    std::cout << "[Friend Display] Model: " << antenna.name 
              << " | Freq: " << antenna.spec.frequency << " MHz"
              << " | Gain: " << antenna.spec.gain << " dBi" << std::endl;
}

void AntennaManager::directDisplay(const OmnidirectionalAntenna& antenna) const {
    std::cout << "[Friend Display - Omni] Model: " << antenna.name 
              << " | Freq: " << antenna.spec.frequency << " MHz"
              << " | Gain: " << antenna.spec.gain << " dBi"
              << " | Beamwidth: " << antenna.beamwidth << " deg" << std::endl;
}

void AntennaManager::directDisplay(const DirectionalAntenna& antenna) const {
    std::cout << "[Friend Display - Directional] Model: " << antenna.name 
              << " | Freq: " << antenna.spec.frequency << " MHz"
              << " | Gain: " << antenna.spec.gain << " dBi"
              << " | Front-to-Back: " << antenna.frontToBackRatio << " dB" << std::endl;
}

AntennaStatistics AntennaManager::computeStatistics(const std::vector<Antenna*>& list) {
    AntennaStatistics stats = {0.0, -1e9, 1e9, 0.0, 0.0, "N/A"};
    if (list.empty()) {
        return stats;
    }

    double totalFrequency = 0.0;
    for (const auto* ant : list) {
        double g = ant->spec.gain;
        double f = ant->spec.frequency;

        stats.totalGain += g;
        totalFrequency += f;

        if (g > stats.maxGain) {
            stats.maxGain = g;
            stats.bestAntennaName = ant->name;
        }
        if (g < stats.minGain) {
            stats.minGain = g;
        }
    }

    stats.averageGain = stats.totalGain / list.size();
    stats.averageFrequency = totalFrequency / list.size();

    historyStats.push_back(stats);
    return stats;
}

void AntennaManager::displayStatistics(const AntennaStatistics& stats) const {
    std::cout << "\n==========================================" << std::endl;
    std::cout << "         " << managerTitle << "         " << std::endl;
    std::cout << "==========================================" << std::endl;
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Best Antenna Model     : " << stats.bestAntennaName << std::endl;
    std::cout << "Maximum Gain           : " << stats.maxGain << " dBi" << std::endl;
    std::cout << "Minimum Gain           : " << stats.minGain << " dBi" << std::endl;
    std::cout << "Average Gain           : " << stats.averageGain << " dBi" << std::endl;
    std::cout << "Total Combined Gain    : " << stats.totalGain << " dBi" << std::endl;
    std::cout << "Average Frequency      : " << stats.averageFrequency << " MHz" << std::endl;
    std::cout << "==========================================\n" << std::endl;
}

void AntennaManager::boostGain(Antenna& antenna, double deltaGain) {
    antenna.spec.gain += deltaGain;
    std::cout << "[Friend Boost] Antenna \"" << antenna.name << "\" gain increased by " 
              << deltaGain << " dBi. New gain: " << antenna.spec.gain << " dBi" << std::endl;
}

void AntennaManager::tuneFrequency(Antenna& antenna, double targetFreq) {
    antenna.spec.frequency = targetFreq;
    std::cout << "[Friend Tune] Antenna \"" << antenna.name << "\" frequency tuned to: " 
              << antenna.spec.frequency << " MHz" << std::endl;
}
