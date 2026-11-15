#include "RelayManager.h"
#include <algorithm>
#include <iostream>

void RelayManager::addRelay(std::shared_ptr<RadioRelay> relay) {
    if (!relay) {
        throw InvalidDataException("Attempted to add null relay pointer.");
    }
    m_relays.push_back(relay);
}

size_t RelayManager::size() const {
    return m_relays.size();
}

bool RelayManager::empty() const {
    return m_relays.empty();
}

void RelayManager::clear() {
    m_relays.clear();
}

RadioRelay& RelayManager::operator[](size_t index) {
    if (index >= m_relays.size()) {
        throw IndexOutOfBoundsException(index, m_relays.size());
    }
    return *m_relays[index];
}

const RadioRelay& RelayManager::operator[](size_t index) const {
    if (index >= m_relays.size()) {
        throw IndexOutOfBoundsException(index, m_relays.size());
    }
    return *m_relays[index];
}

void RelayManager::printAll(std::ostream& os) const {
    if (m_relays.empty()) {
        os << "  (Empty)\n";
        return;
    }
    for (size_t i = 0; i < m_relays.size(); ++i) {
        os << "  #" << (i + 1) << " " << *m_relays[i] << "\n";
    }
}

void RelayManager::sortByCurrent() {
    for (size_t i = 0; i < m_relays.size(); ++i) {
        size_t minIdx = i;
        for (size_t j = i + 1; j < m_relays.size(); ++j) {
            if (*m_relays[j] <= *m_relays[minIdx]) {
                minIdx = j;
            }
        }
        if (minIdx != i) {
            std::swap(m_relays[i], m_relays[minIdx]);
        }
    }
}

void RelayManager::saveToFile(const std::string& filename) const {
    std::fstream file(filename, std::ios::in | std::ios::out | std::ios::trunc);
    if (!file.is_open()) {
        throw FileException("Cannot open file for writing: " + filename);
    }

    file << m_relays.size() << "\n";
    for (const auto& relay : m_relays) {
        relay->writeToFile(file);
    }
    file.close();
}

void RelayManager::loadFromFile(const std::string& filename) {
    std::fstream file(filename, std::ios::in);
    if (!file.is_open()) {
        throw FileException("Cannot open file for reading: " + filename);
    }

    size_t count = 0;
    if (!(file >> count)) {
        file.close();
        throw FileException("Failed to read header from: " + filename);
    }

    std::vector<std::shared_ptr<RadioRelay>> loaded;
    for (size_t i = 0; i < count; ++i) {
        std::string kind;
        if (!(file >> kind)) {
            file.close();
            throw FileException("Unexpected EOF while reading relay #" + std::to_string(i + 1));
        }

        std::shared_ptr<RadioRelay> relay;
        if (kind == "BASE") {
            relay = std::make_shared<RadioRelay>();
        } else if (kind == "EMR") {
            relay = std::make_shared<ElectromagneticRelay>();
        } else if (kind == "SSR") {
            relay = std::make_shared<SolidStateRelay>();
        } else {
            file.close();
            throw FileException("Unknown relay type: " + kind);
        }

        relay->readFromFile(file);
        loaded.push_back(relay);
    }

    file.close();
    m_relays = std::move(loaded);
}

void RelayManager::appendToFile(const std::string& filename, const RadioRelay& relay) const {
    std::fstream file(filename, std::ios::out | std::ios::app);
    if (!file.is_open()) {
        throw FileException("Cannot open file for appending: " + filename);
    }
    relay.writeToFile(file);
    file.close();
}
