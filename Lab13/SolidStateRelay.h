#ifndef SOLID_STATE_RELAY_H
#define SOLID_STATE_RELAY_H

#include "RadioRelay.h"

// Derived class 2: Solid State Relay (SSR)
// Additional field: optical/galvanic isolation voltage (isolationVoltage, V)
class SolidStateRelay : public RadioRelay {
private:
    double m_isolationVoltage;

    static void validateIsolation(double isoVoltage);

public:
    SolidStateRelay();
    SolidStateRelay(const std::string& model, double coilVoltage, double maxCurrent,
                    int contactGroups, double isolationVoltage);
    virtual ~SolidStateRelay() override = default;

    void setIsolationVoltage(double isoVoltage);
    double getIsolationVoltage() const;

    virtual std::string getType() const override;
    virtual void print(std::ostream& os) const override;
    virtual void writeToFile(std::ostream& os) const override;
    virtual void readFromFile(std::istream& is) override;
};

#endif // SOLID_STATE_RELAY_H
