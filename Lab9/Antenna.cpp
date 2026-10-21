#include "Antenna.h"

using namespace std;

bool Antenna::isFrequencyValid(double freq) const {
    return freq > 0.0 && freq <= 100000.0;
}

bool Antenna::isGainValid(double g) const {
    return g >= -20.0 && g <= 60.0;
}

Antenna::Antenna() {
    name = "Default Antenna";
    spec.frequency = 2400.0;
    spec.gain = 2.15;
}

Antenna::Antenna(string name, double frequency, double gain) {
    setName(name);
    setFrequency(frequency);
    setGain(gain);
}

Antenna::~Antenna() {
    // Destructor
}

void Antenna::setName(string name) {
    if (name.empty()) {
        cout << "[Warning] Name cannot be empty! Set to 'Unnamed'." << endl;
        this->name = "Unnamed";
    } else {
        this->name = name;
    }
}

void Antenna::setFrequency(double freq) {
    if (isFrequencyValid(freq)) {
        spec.frequency = freq;
    } else {
        cout << "[Warning] Invalid frequency (" << freq << " MHz). Set to 2400 MHz." << endl;
        spec.frequency = 2400.0;
    }
}

void Antenna::setGain(double g) {
    if (isGainValid(g)) {
        spec.gain = g;
    } else {
        cout << "[Warning] Invalid gain (" << g << " dBi). Set to 0 dBi." << endl;
        spec.gain = 0.0;
    }
}

string Antenna::getName() const {
    return name;
}

double Antenna::getFrequency() const {
    return spec.frequency;
}

double Antenna::getGain() const {
    return spec.gain;
}

void Antenna::inputData() {
    cout << "Enter antenna name: ";
    cin >> ws;
    getline(cin, name);
    setName(name);

    double freq;
    cout << "Enter frequency (MHz): ";
    cin >> freq;
    setFrequency(freq);

    double g;
    cout << "Enter gain (dBi): ";
    cin >> g;
    setGain(g);
}

void Antenna::printData() const {
    cout << "--- Antenna: " << name << " ---" << endl;
    cout << "Frequency: " << spec.frequency << " MHz" << endl;
    cout << "Gain: " << spec.gain << " dBi" << endl;
}
