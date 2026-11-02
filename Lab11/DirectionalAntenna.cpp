#include "DirectionalAntenna.h"

bool DirectionalAntenna::isRatioValid(double ratio) const {
    return ratio >= 0.0 && ratio <= 60.0;
}

DirectionalAntenna::DirectionalAntenna() : Antenna(), frontToBackRatio(15.0) {
}

DirectionalAntenna::DirectionalAntenna(std::string name, double frequency, double gain, double fbr)
    : Antenna(name, frequency, gain) {
    setFrontToBackRatio(fbr);
}

DirectionalAntenna::~DirectionalAntenna() {
}

void DirectionalAntenna::setFrontToBackRatio(double ratio) {
    if (isRatioValid(ratio)) {
        frontToBackRatio = ratio;
    } else {
        std::cout << "[Warning] Invalid Front-to-Back ratio: " << ratio << " dB. Set to default (15 dB).\n";
        frontToBackRatio = 15.0;
    }
}

double DirectionalAntenna::getFrontToBackRatio() const {
    return frontToBackRatio;
}

void DirectionalAntenna::inputData() {
    Antenna::inputData();
    double ratio;
    std::cout << "Enter front-to-back ratio (dB): ";
    std::cin >> ratio;
    setFrontToBackRatio(ratio);
}

void DirectionalAntenna::printData() const {
    Antenna::printData();
    std::cout << "Type: Directional Antenna" << std::endl;
    std::cout << "Front-to-Back Ratio: " << frontToBackRatio << " dB" << std::endl;
}
