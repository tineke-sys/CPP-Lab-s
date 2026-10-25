#include <iostream>
#include <vector>
#include "Antenna.h"
#include "OmnidirectionalAntenna.h"
#include "DirectionalAntenna.h"

using namespace std;

// Print antenna details using base class reference (Polymorphism)
void showAntennaInfo(const Antenna& antenna) {
    antenna.printData();
}

int main() {
    // 1. Polymorphism demo with references
    cout << "=== 1. Polymorphism Demo ===" << endl;
    OmnidirectionalAntenna omni1("TP-Link TL-ANT2408CL", 2400.0, 8.0, 360.0);
    DirectionalAntenna dir1("Ubiquiti RocketDish", 5000.0, 30.0, 34.0);

    showAntennaInfo(omni1);
    showAntennaInfo(dir1);

    // 2. Vector of base class pointers
    cout << "\n=== 2. Dynamic Array (vector) of Antennas ===" << endl;
    vector<Antenna*> antennaList;

    antennaList.push_back(new OmnidirectionalAntenna("MikroTik HGO-antenna", 2400.0, 9.0, 360.0));
    antennaList.push_back(new DirectionalAntenna("Yagi-Uda 144MHz", 144.0, 12.5, 18.0));

    // Print all antennas
    cout << "\nAntenna list in vector:" << endl;
    for (size_t i = 0; i < antennaList.size(); ++i) {
        cout << "\nItem #" << (i + 1) << ":";
        antennaList[i]->printData();
    }

    // 3. Simple calculations
    cout << "\n=== 3. Calculations ===" << endl;
    if (!antennaList.empty()) {
        double maxGain = antennaList[0]->getGain();
        double sumFrequency = 0.0;
        string maxGainName = antennaList[0]->getName();

        for (size_t i = 0; i < antennaList.size(); ++i) {
            sumFrequency += antennaList[i]->getFrequency();
            if (antennaList[i]->getGain() > maxGain) {
                maxGain = antennaList[i]->getGain();
                maxGainName = antennaList[i]->getName();
            }
        }

        cout << "Max Gain: " << maxGain << " dBi (Model: " << maxGainName << ")" << endl;
        cout << "Average Frequency: " << (sumFrequency / antennaList.size()) << " MHz" << endl;
    }

    // 4. Data validation test
    cout << "\n=== 4. Validation Test ===" << endl;
    DirectionalAntenna testAntenna;
    cout << "Trying to set invalid values (frequency = -50, ratio = 999):" << endl;
    testAntenna.setFrequency(-50.0);
    testAntenna.setFrontToBackRatio(999.0);
    testAntenna.printData();

    // 5. Cleanup dynamic memory
    for (size_t i = 0; i < antennaList.size(); ++i) {
        delete antennaList[i];
    }
    antennaList.clear();

    cout << "\nProgram finished successfully." << endl;
    return 0;
}
