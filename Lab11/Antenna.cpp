#include "Antenna.h"

bool Antenna::isFrequencyValid(double freq) const {
    return freq > 0.0 && freq <= 100000.0;
}

bool Antenna::isGainValid(double g) const {
    return g >= -10.0 && g <= 60.0;
}

Antenna::Antenna() : name("Unknown Antenna") {
    spec.frequency = 2400.0;
    spec.gain = 0.0;
}

Antenna::Antenna(std::string name, double frequency, double gain) {
    setName(name);
    setFrequency(frequency);
    setGain(gain);
}

Antenna::~Antenna() {
}

void Antenna::setName(std::string name) {
    if (!name.empty()) {
        this->name = name;
    } else {
        this->name = "Unknown Antenna";
    }
}

void Antenna::setFrequency(double freq) {
    if (isFrequencyValid(freq)) {
        spec.frequency = freq;
    } else {
        std::cout << "[Antenna Warning] Incorrect frequency value: " << freq << " MHz. Default set (2400 MHz).\n";
        spec.frequency = 2400.0;
    }
}

void Antenna::setGain(double g) {
    if (isGainValid(g)) {
        spec.gain = g;
    } else {
        std::cout << "[Antenna Warning] Incorrect gain value: " << g << " dBi. Default set (0 dBi).\n";
        spec.gain = 0.0;
    }
}

std::string Antenna::getName() const {
    return name;
}

double Antenna::getFrequency() const {
    return spec.frequency;
}

double Antenna::getGain() const {
    return spec.gain;
}

void Antenna::inputData() {
    std::cout << "Enter antenna model name: ";
    std::getline(std::cin >> std::ws, name);

    double freq;
    std::cout << "Enter frequency (MHz): ";
    std::cin >> freq;
    setFrequency(freq);

    double g;
    std::cout << "Enter gain (dBi): ";
    std::cin >> g;
    setGain(g);
}

void Antenna::printData() const {
    std::cout << "\n--- Antenna Details ---" << std::endl;
    std::cout << "Model: " << name << std::endl;
    std::cout << "Frequency: " << spec.frequency << " MHz" << std::endl;
    std::cout << "Gain: " << spec.gain << " dBi" << std::endl;
}

