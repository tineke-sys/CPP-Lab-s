#ifndef OMNIDIRECTIONAL_ANTENNA_H
#define OMNIDIRECTIONAL_ANTENNA_H

#include "Antenna.h"

// Дочірній клас 1: Всеспрямована антена
class OmnidirectionalAntenna : public Antenna {
private:
    double beamwidth; // Горизонтальна ширина діаграми спрямованості у градусах (зазвичай 360°)

    bool isBeamwidthValid(double bw) const;

public:
    OmnidirectionalAntenna();
    OmnidirectionalAntenna(std::string name, double frequency, double gain, double beamwidth);
    virtual ~OmnidirectionalAntenna();

    void setBeamwidth(double bw);
    double getBeamwidth() const;

    virtual void inputData();
    virtual void printData() const;

    // Дружній клас має доступ до полів OmnidirectionalAntenna
    friend class AntennaManager;
};

#endif // OMNIDIRECTIONAL_ANTENNA_H

