#ifndef OMNIDIRECTIONAL_ANTENNA_H
#define OMNIDIRECTIONAL_ANTENNA_H

#include "Antenna.h"

// Derived class 1: Omnidirectional antenna
class OmnidirectionalAntenna : public Antenna {
private:
    double beamwidth; // Horizontal beamwidth in degrees (usually 360)

    bool isBeamwidthValid(double bw) const;

public:
    OmnidirectionalAntenna();
    OmnidirectionalAntenna(std::string name, double frequency, double gain, double beamwidth);
    virtual ~OmnidirectionalAntenna();

    void setBeamwidth(double bw);
    double getBeamwidth() const;

    virtual void inputData();
    virtual void printData() const;
};

#endif // OMNIDIRECTIONAL_ANTENNA_H
