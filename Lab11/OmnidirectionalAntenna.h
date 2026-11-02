#ifndef OMNIDIRECTIONAL_ANTENNA_H
#define OMNIDIRECTIONAL_ANTENNA_H

#include "Antenna.h"

// Derived class: Omnidirectional antenna
class OmnidirectionalAntenna : public Antenna {
private:
    double beamwidth;

    bool isBeamwidthValid(double bw) const;

public:
    OmnidirectionalAntenna();
    OmnidirectionalAntenna(std::string name, double frequency, double gain, double beamwidth);
    virtual ~OmnidirectionalAntenna();

    void setBeamwidth(double bw);
    double getBeamwidth() const;

    virtual void inputData();
    virtual void printData() const;

    friend class AntennaManager;
};

#endif // OMNIDIRECTIONAL_ANTENNA_H
