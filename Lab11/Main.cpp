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

    AntennaManager manager("Antenna Optimization & Control Lab");

    OmnidirectionalAntenna omni1("Omni-A1", 2400.0, 8.0, 360.0);
    OmnidirectionalAntenna omni2("Omni-A2", 5150.0, 9.0, 360.0);
    DirectionalAntenna dir1("Dir-B1", 5800.0, 30.0, 34.0);
    DirectionalAntenna dir2("Dir-B2", 144.0, 12.5, 18.0);

    // 1. Display data via friend class
    cout << "--- 1. Displaying Antenna Data via Friend Class Methods ---" << endl;
    manager.directDisplay(omni1);
    manager.directDisplay(omni2);
    manager.directDisplay(dir1);
    manager.directDisplay(dir2);

    // Dynamic array of base class pointers
    vector<Antenna*> antennas;
    antennas.push_back(&omni1);
    antennas.push_back(&omni2);
    antennas.push_back(&dir1);
    antennas.push_back(&dir2);

    // 2. Statistical calculation using friend class
    cout << "\n--- 2. Computing Statistical Metrics via Friend Class ---" << endl;
    AntennaStatistics stats = manager.computeStatistics(antennas);
    manager.displayStatistics(stats);

    // 3. Direct modification of protected/private data via friend class
    cout << "--- 3. Direct Modification of Protected/Private Data via Friend Class ---" << endl;
    manager.boostGain(omni1, 1.5);
    manager.tuneFrequency(dir2, 145.5);

    cout << "\nAfter modifications:" << endl;
    manager.directDisplay(omni1);
    manager.directDisplay(dir2);

    // 4. Recalculate statistics
    cout << "\n--- 4. Re-calculating Metrics After Parameter Boost ---" << endl;
    AntennaStatistics updatedStats = manager.computeStatistics(antennas);
    manager.displayStatistics(updatedStats);

    cout << "Program completed successfully." << endl;
    return 0;
}
