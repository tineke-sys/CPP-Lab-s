#include "SolidStateRelay.h"

void SolidStateRelay::validateIsolation(double isoVoltage) {
    if (isoVoltage < 100.0 || isoVoltage > 20000.0) {
        throw InvalidDataException("Isolation voltage must be in range [100, 20000] V. Got: " +
                                   std::to_string(isoVoltage));
    }
}

SolidStateRelay::SolidStateRelay()
    : RadioRelay("SSR-Generic", 5.0, 25.0, 1), m_isolationVoltage(2500.0) {}

SolidStateRelay::SolidStateRelay(const std::string& model, double coilVoltage, double maxCurrent,
                                 int contactGroups, double isolationVoltage)
    : RadioRelay(model, coilVoltage, maxCurrent, contactGroups) {
    validateIsolation(isolationVoltage);
    m_isolationVoltage = isolationVoltage;
}

void SolidStateRelay::setIsolationVoltage(double isoVoltage) {
    validateIsolation(isoVoltage);
    m_isolationVoltage = isoVoltage;
}

double SolidStateRelay::getIsolationVoltage() const {
    return m_isolationVoltage;
}

std::string SolidStateRelay::getType() const {
    return "SSR";
}

void SolidStateRelay::print(std::ostream& os) const {
    RadioRelay::print(os);
    os << ", Iso: " << m_isolationVoltage << " V";
}

void SolidStateRelay::writeToFile(std::ostream& os) const {
    os << "SSR " << m_modelName << " "
       << m_specs.coilVoltage << " "
       << m_specs.maxSwitchCurrent << " "
       << m_specs.contactGroups << " "
       << m_isolationVoltage << "\n";
}

void SolidStateRelay::readFromFile(std::istream& is) {
    std::string model;
    double voltage, current, isolation;
    int groups;

    if (!(is >> model >> voltage >> current >> groups >> isolation)) {
        throw FileException("Failed to read SSR fields from stream.");
    }

    validateVoltage(voltage);
    validateCurrent(current);
    validateGroups(groups);
    validateIsolation(isolation);

    m_modelName = model;
    m_specs.coilVoltage = voltage;
    m_specs.maxSwitchCurrent = current;
    m_specs.contactGroups = groups;
    m_isolationVoltage = isolation;
}
