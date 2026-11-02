#ifndef ANTENNA_MANAGER_H
#define ANTENNA_MANAGER_H

#include <vector>
#include <string>
#include "Antenna.h"
#include "OmnidirectionalAntenna.h"
#include "DirectionalAntenna.h"

struct AntennaStatistics {
    double totalGain;
    double maxGain;
    double minGain;
    double averageGain;
    double averageFrequency;
    std::string bestAntennaName;
};

// Friend class for processing and analyzing antenna data
class AntennaManager {
private:
    std::string managerTitle;
    std::vector<AntennaStatistics> historyStats;

public:
    AntennaManager(std::string title = "Antenna Control & Analytics Center");
    ~AntennaManager();

    // Direct access to private and protected members via friend declaration
    void directInput(Antenna& antenna);
    void directInput(OmnidirectionalAntenna& antenna);
    void directInput(DirectionalAntenna& antenna);

    void directDisplay(const Antenna& antenna) const;
    void directDisplay(const OmnidirectionalAntenna& antenna) const;
    void directDisplay(const DirectionalAntenna& antenna) const;

    AntennaStatistics computeStatistics(const std::vector<Antenna*>& list);
    void displayStatistics(const AntennaStatistics& stats) const;

    void boostGain(Antenna& antenna, double deltaGain);
    void tuneFrequency(Antenna& antenna, double targetFreq);
};

#endif // ANTENNA_MANAGER_H
