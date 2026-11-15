#ifndef RADIO_RELAY_H
#define RADIO_RELAY_H

#include <iostream>
#include <string>
#include "RadioRelayExceptions.h"

// Variant 11: Radio Relay parameters structure
struct RelaySpecs {
    double coilVoltage;       // Coil voltage, V
    double maxSwitchCurrent;  // Max switching current, A
    int contactGroups;        // Number of contact groups
};

// Base class: RadioRelay
class RadioRelay {
protected:
    std::string m_modelName;
    RelaySpecs m_specs;

    static void validateVoltage(double voltage);
    static void validateCurrent(double current);
    static void validateGroups(int groups);

public:
    RadioRelay();
    RadioRelay(const std::string& model, double coilVoltage, double maxCurrent, int contactGroups);
    virtual ~RadioRelay() = default;

    void setModelName(const std::string& model);
    void setCoilVoltage(double voltage);
    void setMaxSwitchCurrent(double current);
    void setContactGroups(int groups);

    std::string getModelName() const;
    double getCoilVoltage() const;
    double getMaxSwitchCurrent() const;
    int getContactGroups() const;
    const RelaySpecs& getSpecs() const;

    virtual std::string getType() const;
    virtual void print(std::ostream& os) const;
    virtual void writeToFile(std::ostream& os) const;
    virtual void readFromFile(std::istream& is);

    virtual bool operator<(const RadioRelay& other) const;
    virtual bool operator<=(const RadioRelay& other) const;
    virtual bool operator==(const RadioRelay& other) const;

    friend std::ostream& operator<<(std::ostream& os, const RadioRelay& relay);
    friend std::istream& operator>>(std::istream& is, RadioRelay& relay);
};

#endif // RADIO_RELAY_H
