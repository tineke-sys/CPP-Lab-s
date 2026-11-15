#ifndef RELAY_MANAGER_H
#define RELAY_MANAGER_H

#include <vector>
#include <memory>
#include <string>
#include <fstream>
#include "RadioRelay.h"
#include "ElectromagneticRelay.h"
#include "SolidStateRelay.h"
#include "RadioRelayExceptions.h"

// Manages dynamic collection (std::vector) of RadioRelay pointers
// Handles bidirectional file I/O (std::fstream) and exception safety
class RelayManager {
private:
    std::vector<std::shared_ptr<RadioRelay>> m_relays;

public:
    RelayManager() = default;
    ~RelayManager() = default;

    void addRelay(std::shared_ptr<RadioRelay> relay);
    size_t size() const;
    bool empty() const;
    void clear();

    RadioRelay& operator[](size_t index);
    const RadioRelay& operator[](size_t index) const;

    void printAll(std::ostream& os = std::cout) const;
    void sortByCurrent();

    // Bidirectional file I/O using std::fstream
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
    void appendToFile(const std::string& filename, const RadioRelay& relay) const;
};

#endif // RELAY_MANAGER_H
