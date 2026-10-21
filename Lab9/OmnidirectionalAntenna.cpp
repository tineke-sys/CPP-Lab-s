#include "OmnidirectionalAntenna.h"

using namespace std;

bool OmnidirectionalAntenna::isBeamwidthValid(double bw) const {
    return bw > 0.0 && bw <= 360.0;
}

OmnidirectionalAntenna::OmnidirectionalAntenna() : Antenna("Omni Antenna", 2400.0, 5.0) {
    beamwidth = 360.0;
}

OmnidirectionalAntenna::OmnidirectionalAntenna(string name, double frequency, double gain, double beamwidth)
    : Antenna(name, frequency, gain) {
    setBeamwidth(beamwidth);
}

OmnidirectionalAntenna::~OmnidirectionalAntenna() {
    // Destructor
}

void OmnidirectionalAntenna::setBeamwidth(double bw) {
    if (isBeamwidthValid(bw)) {
        beamwidth = bw;
    } else {
        cout << "[Warning] Invalid beamwidth (" << bw << "). Set to 360.0 deg." << endl;
        beamwidth = 360.0;
    }
}

double OmnidirectionalAntenna::getBeamwidth() const {
    return beamwidth;
}

void OmnidirectionalAntenna::inputData() {
    Antenna::inputData();

    double bw;
    cout << "Enter horizontal beamwidth (degrees): ";
    cin >> bw;
    setBeamwidth(bw);
}

void OmnidirectionalAntenna::printData() const {
    cout << "\n=== [Omnidirectional Antenna] ===" << endl;
    Antenna::printData();
    cout << "Beamwidth: " << beamwidth << " deg" << endl;
    cout << "=================================" << endl;
}
