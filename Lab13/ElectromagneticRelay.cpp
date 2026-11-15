#include "ElectromagneticRelay.h"

void ElectromagneticRelay::validateResistance(double resistance) {
    if (resistance <= 0.0 || resistance > 100000.0) {
        throw InvalidDataException("Coil resistance must be in range (0, 100000] Ohm. Got: " +
                                   std::to_string(resistance));
    }
}

ElectromagneticRelay::ElectromagneticRelay()
    : RadioRelay("EMR-Generic", 12.0, 10.0, 2), m_coilResistance(400.0) {}

ElectromagneticRelay::ElectromagneticRelay(const std::string& model, double coilVoltage, double maxCurrent,
                                           int contactGroups, double coilResistance)
    : RadioRelay(model, coilVoltage, maxCurrent, contactGroups) {
    validateResistance(coilResistance);
    m_coilResistance = coilResistance;
}

void ElectromagneticRelay::setCoilResistance(double resistance) {
    validateResistance(resistance);
    m_coilResistance = resistance;
}

double ElectromagneticRelay::getCoilResistance() const {
    return m_coilResistance;
}

std::string ElectromagneticRelay::getType() const {
    return "EMR";
}

void ElectromagneticRelay::print(std::ostream& os) const {
    RadioRelay::print(os);
    os << ", Coil R: " << m_coilResistance << " Ohm";
}

void ElectromagneticRelay::writeToFile(std::ostream& os) const {
    os << "EMR " << m_modelName << " "
       << m_specs.coilVoltage << " "
       << m_specs.maxSwitchCurrent << " "
       << m_specs.contactGroups << " "
       << m_coilResistance << "\n";
}

void ElectromagneticRelay::readFromFile(std::istream& is) {
    std::string model;
    double voltage, current, resistance;
    int groups;

    if (!(is >> model >> voltage >> current >> groups >> resistance)) {
        throw FileException("Failed to read EMR fields from stream.");
    }

    validateVoltage(voltage);
    validateCurrent(current);
    validateGroups(groups);
    validateResistance(resistance);

    m_modelName = model;
    m_specs.coilVoltage = voltage;
    m_specs.maxSwitchCurrent = current;
    m_specs.contactGroups = groups;
    m_coilResistance = resistance;
}
