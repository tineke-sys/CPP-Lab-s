#include "OmnidirectionalAntenna.h"

bool OmnidirectionalAntenna::isBeamwidthValid(double bw) const {
    return bw > 0.0 && bw <= 360.0;
}

OmnidirectionalAntenna::OmnidirectionalAntenna() : Antenna(), beamwidth(360.0) {
}

OmnidirectionalAntenna::OmnidirectionalAntenna(std::string name, double frequency, double gain, double beamwidth)
    : Antenna(name, frequency, gain) {
    setBeamwidth(beamwidth);
}

OmnidirectionalAntenna::~OmnidirectionalAntenna() {
}

void OmnidirectionalAntenna::setBeamwidth(double bw) {
    if (isBeamwidthValid(bw)) {
        beamwidth = bw;
    } else {
        std::cout << "[Warning] Invalid beamwidth: " << bw << " deg. Set to default (360 deg).\n";
        beamwidth = 360.0;
    }
}

double OmnidirectionalAntenna::getBeamwidth() const {
    return beamwidth;
}

void OmnidirectionalAntenna::inputData() {
    Antenna::inputData();
    double bw;
    std::cout << "Enter horizontal beamwidth (degrees): ";
    std::cin >> bw;
    setBeamwidth(bw);
}

void OmnidirectionalAntenna::printData() const {
    Antenna::printData();
    std::cout << "Type: Omnidirectional Antenna" << std::endl;
    std::cout << "Beamwidth: " << beamwidth << " deg" << std::endl;
}
