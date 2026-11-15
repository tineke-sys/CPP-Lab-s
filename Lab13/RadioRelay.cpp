#include "RadioRelay.h"

void RadioRelay::validateVoltage(double voltage) {
    if (voltage <= 0.0 || voltage > 1000.0) {
        throw InvalidDataException("Coil voltage must be in range (0, 1000] V. Got: " +
                                   std::to_string(voltage));
    }
}

void RadioRelay::validateCurrent(double current) {
    if (current <= 0.0 || current > 200.0) {
        throw InvalidDataException("Max current must be in range (0, 200] A. Got: " +
                                   std::to_string(current));
    }
}

void RadioRelay::validateGroups(int groups) {
    if (groups <= 0 || groups > 32) {
        throw InvalidDataException("Contact groups must be in range [1, 32]. Got: " +
                                   std::to_string(groups));
    }
}

RadioRelay::RadioRelay()
    : m_modelName("Generic-Relay"), m_specs{12.0, 5.0, 1} {}

RadioRelay::RadioRelay(const std::string& model, double coilVoltage, double maxCurrent, int contactGroups)
    : m_modelName(model) {
    validateVoltage(coilVoltage);
    validateCurrent(maxCurrent);
    validateGroups(contactGroups);

    m_specs.coilVoltage = coilVoltage;
    m_specs.maxSwitchCurrent = maxCurrent;
    m_specs.contactGroups = contactGroups;
}

void RadioRelay::setModelName(const std::string& model) {
    if (model.empty()) {
        throw InvalidDataException("Model name cannot be empty.");
    }
    m_modelName = model;
}

void RadioRelay::setCoilVoltage(double voltage) {
    validateVoltage(voltage);
    m_specs.coilVoltage = voltage;
}

void RadioRelay::setMaxSwitchCurrent(double current) {
    validateCurrent(current);
    m_specs.maxSwitchCurrent = current;
}

void RadioRelay::setContactGroups(int groups) {
    validateGroups(groups);
    m_specs.contactGroups = groups;
}

std::string RadioRelay::getModelName() const {
    return m_modelName;
}

double RadioRelay::getCoilVoltage() const {
    return m_specs.coilVoltage;
}

double RadioRelay::getMaxSwitchCurrent() const {
    return m_specs.maxSwitchCurrent;
}

int RadioRelay::getContactGroups() const {
    return m_specs.contactGroups;
}

const RelaySpecs& RadioRelay::getSpecs() const {
    return m_specs;
}

std::string RadioRelay::getType() const {
    return "Base";
}

void RadioRelay::print(std::ostream& os) const {
    os << "[" << getType() << "] " << m_modelName
       << " | Voltage: " << m_specs.coilVoltage << "V"
       << ", Current: " << m_specs.maxSwitchCurrent << "A"
       << ", Groups: " << m_specs.contactGroups;
}

void RadioRelay::writeToFile(std::ostream& os) const {
    os << "BASE " << m_modelName << " "
       << m_specs.coilVoltage << " "
       << m_specs.maxSwitchCurrent << " "
       << m_specs.contactGroups << "\n";
}

void RadioRelay::readFromFile(std::istream& is) {
    std::string model;
    double voltage, current;
    int groups;

    if (!(is >> model >> voltage >> current >> groups)) {
        throw FileException("Failed to read base relay fields from stream.");
    }

    validateVoltage(voltage);
    validateCurrent(current);
    validateGroups(groups);

    m_modelName = model;
    m_specs.coilVoltage = voltage;
    m_specs.maxSwitchCurrent = current;
    m_specs.contactGroups = groups;
}

bool RadioRelay::operator<(const RadioRelay& other) const {
    return this->m_specs.maxSwitchCurrent < other.m_specs.maxSwitchCurrent;
}

bool RadioRelay::operator<=(const RadioRelay& other) const {
    return this->m_specs.maxSwitchCurrent <= other.m_specs.maxSwitchCurrent;
}

bool RadioRelay::operator==(const RadioRelay& other) const {
    return this->m_specs.coilVoltage == other.m_specs.coilVoltage &&
           this->m_specs.maxSwitchCurrent == other.m_specs.maxSwitchCurrent &&
           this->m_specs.contactGroups == other.m_specs.contactGroups;
}

std::ostream& operator<<(std::ostream& os, const RadioRelay& relay) {
    relay.print(os);
    return os;
}

std::istream& operator>>(std::istream& is, RadioRelay& relay) {
    std::string model;
    double voltage, current;
    int groups;

    std::cout << "Enter model name: ";
    is >> model;
    std::cout << "Enter coil voltage (V): ";
    if (!(is >> voltage)) throw InvalidDataException("Invalid input for voltage.");
    std::cout << "Enter max current (A): ";
    if (!(is >> current)) throw InvalidDataException("Invalid input for current.");
    std::cout << "Enter contact groups: ";
    if (!(is >> groups)) throw InvalidDataException("Invalid input for groups.");

    relay.setModelName(model);
    relay.setCoilVoltage(voltage);
    relay.setMaxSwitchCurrent(current);
    relay.setContactGroups(groups);

    return is;
}
