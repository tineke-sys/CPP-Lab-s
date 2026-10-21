#ifndef ANTENNA_H
#define ANTENNA_H

#include <iostream>
#include <string>

// Specification of antenna
struct AntennaSpec {
    double frequency; // Frequency, MHz
    double gain;      // Gain, dBi
};

// Base class: Antenna
class Antenna {
protected:
    std::string name;
    AntennaSpec spec;

    bool isFrequencyValid(double freq) const;
    bool isGainValid(double g) const;

public:
    Antenna();
    Antenna(std::string name, double frequency, double gain);
    virtual ~Antenna();

    void setName(std::string name);
    void setFrequency(double freq);
    void setGain(double g);

    std::string getName() const;
    double getFrequency() const;
    double getGain() const;

    virtual void inputData();
    virtual void printData() const;
};

#endif // ANTENNA_H
