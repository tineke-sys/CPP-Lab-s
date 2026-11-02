#ifndef ANTENNA_H
#define ANTENNA_H

#include <iostream>
#include <string>

class AntennaManager;

struct AntennaSpec {
    double frequency;
    double gain;
};

// Base class
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

    friend class AntennaManager;
};

#endif // ANTENNA_H
