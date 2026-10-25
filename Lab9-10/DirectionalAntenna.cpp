#include "DirectionalAntenna.h"

using namespace std;

bool DirectionalAntenna::isRatioValid(double ratio) const {
    return ratio >= 0.0 && ratio <= 60.0;
}

DirectionalAntenna::DirectionalAntenna() : Antenna("Directional Antenna", 5000.0, 16.0) {
    frontToBackRatio = 25.0;
}

DirectionalAntenna::DirectionalAntenna(string name, double frequency, double gain, double fbr)
    : Antenna(name, frequency, gain) {
    setFrontToBackRatio(fbr);
}

DirectionalAntenna::~DirectionalAntenna() {
    // Destructor
}

void DirectionalAntenna::setFrontToBackRatio(double ratio) {
    if (isRatioValid(ratio)) {
        frontToBackRatio = ratio;
    } else {
        cout << "[Warning] Invalid front-to-back ratio (" << ratio << " dB). Set to 20.0 dB." << endl;
        frontToBackRatio = 20.0;
    }
}

double DirectionalAntenna::getFrontToBackRatio() const {
    return frontToBackRatio;
}

void DirectionalAntenna::inputData() {
    Antenna::inputData();

    double fbr;
    cout << "Enter front-to-back ratio (dB): ";
    cin >> fbr;
    setFrontToBackRatio(fbr);
}

void DirectionalAntenna::printData() const {
    cout << "\n=== [Directional Antenna] ===" << endl;
    Antenna::printData();
    cout << "Front-to-Back Ratio: " << frontToBackRatio << " dB" << endl;
    cout << "=============================" << endl;
}
