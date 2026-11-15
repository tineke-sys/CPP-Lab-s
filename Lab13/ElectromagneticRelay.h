#ifndef ELECTROMAGNETIC_RELAY_H
#define ELECTROMAGNETIC_RELAY_H

#include "RadioRelay.h"

// Derived class 1: Electromagnetic Relay
// Additional field: coil resistance (coilResistance, Ohm)
class ElectromagneticRelay : public RadioRelay {
private:
    double m_coilResistance;

    static void validateResistance(double resistance);

public:
    ElectromagneticRelay();
    ElectromagneticRelay(const std::string& model, double coilVoltage, double maxCurrent,
                         int contactGroups, double coilResistance);
    virtual ~ElectromagneticRelay() override = default;

    void setCoilResistance(double resistance);
    double getCoilResistance() const;

    virtual std::string getType() const override;
    virtual void print(std::ostream& os) const override;
    virtual void writeToFile(std::ostream& os) const override;
    virtual void readFromFile(std::istream& is) override;
};

#endif // ELECTROMAGNETIC_RELAY_H
