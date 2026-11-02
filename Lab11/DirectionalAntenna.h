#ifndef DIRECTIONAL_ANTENNA_H
#define DIRECTIONAL_ANTENNA_H

#include "Antenna.h"

// Derived class: Directional antenna
class DirectionalAntenna : public Antenna {
private:
    double frontToBackRatio;

    bool isRatioValid(double ratio) const;

public:
    DirectionalAntenna();
    DirectionalAntenna(std::string name, double frequency, double gain, double fbr);
    virtual ~DirectionalAntenna();

    void setFrontToBackRatio(double ratio);
    double getFrontToBackRatio() const;

    virtual void inputData();
    virtual void printData() const;

    friend class AntennaManager;
};

#endif // DIRECTIONAL_ANTENNA_H
