#include "RadioRelay.h"
#include <iomanip>
#include <limits>
#include <utility>

using namespace std;

// ---------- Перевірки валідності ----------
bool RadioRelayList::isVoltageValid(double voltage) const {
    return voltage > 0 && voltage <= MAX_VOLTAGE;
}

bool RadioRelayList::isCurrentValid(double current) const {
    return current > 0 && current <= MAX_CURRENT;
}

bool RadioRelayList::isGroupsValid(int groups) const {
    return groups >= 1 && groups <= MAX_GROUPS;
}

bool RadioRelayList::isIndexValid(int index) const {
    return index >= 1 && index <= static_cast<int>(relays.size());
}

// ---------- Конструктори та деструктор ----------
RadioRelayList::RadioRelayList() {
    // Вектор за замовчуванням порожній
}

RadioRelayList::RadioRelayList(double voltage, double current, int groups) {
    addRelay(voltage, current, groups);
}

RadioRelayList::RadioRelayList(const vector<relay_s_t>& initialRelays) {
    for (const auto& item : initialRelays) {
        addRelay(item.coilVoltage, item.maxSwitchCurrent, item.contactGroups);
    }
}

RadioRelayList::~RadioRelayList() {
    cout << "Destructor called: RadioRelayList object destroyed ("
         << relays.size() << " elements cleared from memory)." << endl;
    relays.clear();
}

// ---------- Додавання ----------
bool RadioRelayList::addRelay(double voltage, double current, int groups) {
    if (!isVoltageValid(voltage)) {
        cout << "[Warning] Invalid coil voltage (" << voltage << " V)! Must be in range (0, "
             << MAX_VOLTAGE << "]. Relay not added." << endl;
        return false;
    }
    if (!isCurrentValid(current)) {
        cout << "[Warning] Invalid switching current (" << current << " A)! Must be in range (0, "
             << MAX_CURRENT << "]. Relay not added." << endl;
        return false;
    }
    if (!isGroupsValid(groups)) {
        cout << "[Warning] Invalid contact groups (" << groups << ")! Must be 1-"
             << MAX_GROUPS << ". Relay not added." << endl;
        return false;
    }

    relays.push_back({voltage, current, groups});
    return true;
}

// ---------- Вставка за позицією (1-based) ----------
bool RadioRelayList::insertRelay(int index, double voltage, double current, int groups) {
    if (index < 1 || index > static_cast<int>(relays.size()) + 1) {
        cout << "[Warning] Invalid insertion index " << index << "! Allowed range: 1-"
             << (relays.size() + 1) << "." << endl;
        return false;
    }
    if (!isVoltageValid(voltage) || !isCurrentValid(current) || !isGroupsValid(groups)) {
        cout << "[Warning] Invalid relay parameters. Insertion cancelled." << endl;
        return false;
    }

    // Вставка за ітератором
    auto it = relays.begin() + (index - 1);
    relays.insert(it, {voltage, current, groups});
    cout << "Relay inserted successfully at position #" << index << "." << endl;
    return true;
}

// ---------- Вилучення за індексом (1-based) ----------
bool RadioRelayList::removeRelay(int index) {
    if (!isIndexValid(index)) {
        cout << "[Warning] Cannot remove: index " << index << " is out of range (1-"
             << relays.size() << ")!" << endl;
        return false;
    }

    auto it = relays.begin() + (index - 1);
    relays.erase(it);
    cout << "Relay #" << index << " removed successfully." << endl;
    return true;
}

// ---------- Обмін елементів ----------
bool RadioRelayList::swapRelays(int index1, int index2) {
    if (!isIndexValid(index1) || !isIndexValid(index2)) {
        cout << "[Warning] Swap failed: invalid indices (" << index1 << ", " << index2 << ")!" << endl;
        return false;
    }

    std::swap(relays[index1 - 1], relays[index2 - 1]);
    cout << "Relays #" << index1 << " and #" << index2 << " swapped successfully." << endl;
    return true;
}

// ---------- Обмін списками (std::vector::swap) ----------
void RadioRelayList::swapLists(RadioRelayList& other) {
    relays.swap(other.relays);
    cout << "Two RadioRelayList objects swapped their internal vectors." << endl;
}

// ---------- Очищення (std::vector::clear) ----------
void RadioRelayList::clear() {
    relays.clear();
    cout << "RadioRelayList cleared. Size is now 0." << endl;
}

// ---------- Ввід ----------
void RadioRelayList::inputData() {
    int n;
    cout << "How many relays would you like to enter? ";
    while (!(cin >> n) || n < 1) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input! Please enter a positive integer: ";
    }

    for (int i = 0; i < n; i++) {
        double voltage, current;
        int groups;
        cout << "\nEntering relay " << (i + 1) << " of " << n << ":" << endl;

        cout << "  Coil voltage (V): ";
        while (!(cin >> voltage)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "  Invalid input! Enter numeric voltage: ";
        }

        cout << "  Max switching current (A): ";
        while (!(cin >> current)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "  Invalid input! Enter numeric current: ";
        }

        cout << "  Contact groups (1-" << MAX_GROUPS << "): ";
        while (!(cin >> groups)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "  Invalid input! Enter integer number of groups: ";
        }

        if (!addRelay(voltage, current, groups)) {
            cout << "  Failed to add relay due to validation errors. Try this item again.\n";
            i--; // Повторити введення цього елемента
        }
    }
}

// ---------- Вивід ----------
void RadioRelayList::printData() const {
    if (relays.empty()) {
        cout << "List is empty (size = 0, capacity = " << relays.capacity() << ")." << endl;
        return;
    }

    cout << "\n+----+------------------+---------------------+----------------+" << endl;
    cout << "| #  | Coil Voltage (V) | Max Current (A)     | Contact Groups |" << endl;
    cout << "+----+------------------+---------------------+----------------+" << endl;

    for (size_t i = 0; i < relays.size(); i++) {
        cout << "| " << setw(2) << (i + 1) << " | "
             << setw(16) << fixed << setprecision(2) << relays[i].coilVoltage << " | "
             << setw(19) << fixed << setprecision(2) << relays[i].maxSwitchCurrent << " | "
             << setw(14) << relays[i].contactGroups << " |" << endl;
    }
    cout << "+----+------------------+---------------------+----------------+" << endl;
    cout << "Total elements (size): " << relays.size()
         << ", Reserved capacity: " << relays.capacity() << "\n" << endl;
}

// ---------- Сетери з валідацією ----------
void RadioRelayList::setCoilVoltage(int index, double voltage) {
    if (!isIndexValid(index)) {
        cout << "[Warning] Invalid relay index #" << index << "!" << endl;
        return;
    }
    if (!isVoltageValid(voltage)) {
        cout << "[Warning] Invalid coil voltage (" << voltage << " V) for relay #" << index << "!" << endl;
        return;
    }
    relays[index - 1].coilVoltage = voltage;
    cout << "Relay #" << index << " coil voltage updated to " << voltage << " V." << endl;
}

void RadioRelayList::setMaxSwitchCurrent(int index, double current) {
    if (!isIndexValid(index)) {
        cout << "[Warning] Invalid relay index #" << index << "!" << endl;
        return;
    }
    if (!isCurrentValid(current)) {
        cout << "[Warning] Invalid max switching current (" << current << " A) for relay #" << index << "!" << endl;
        return;
    }
    relays[index - 1].maxSwitchCurrent = current;
    cout << "Relay #" << index << " switching current updated to " << current << " A." << endl;
}

void RadioRelayList::setContactGroups(int index, int groups) {
    if (!isIndexValid(index)) {
        cout << "[Warning] Invalid relay index #" << index << "!" << endl;
        return;
    }
    if (!isGroupsValid(groups)) {
        cout << "[Warning] Invalid contact groups (" << groups << ") for relay #" << index << "!" << endl;
        return;
    }
    relays[index - 1].contactGroups = groups;
    cout << "Relay #" << index << " contact groups updated to " << groups << "." << endl;
}

// ---------- Інформаційні методи ----------
int RadioRelayList::getCount() const {
    return static_cast<int>(relays.size());
}

size_t RadioRelayList::getCapacity() const {
    return relays.capacity();
}

bool RadioRelayList::isEmpty() const {
    return relays.empty();
}

// ---------- Методи фільтрації ----------
void RadioRelayList::printByMinCurrent(double minCurrent) const {
    cout << "\n--- Relays with switching current >= " << minCurrent << " A ---" << endl;
    bool found = false;
    for (size_t i = 0; i < relays.size(); i++) {
        if (relays[i].maxSwitchCurrent >= minCurrent) {
            cout << "Relay #" << (i + 1)
                 << " -> Voltage: " << relays[i].coilVoltage << " V"
                 << ", Current: " << relays[i].maxSwitchCurrent << " A"
                 << ", Groups: " << relays[i].contactGroups << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No relays found matching the condition." << endl;
    }
}

void RadioRelayList::printByContactGroups(int groups) const {
    cout << "\n--- Relays with exactly " << groups << " contact group(s) ---" << endl;
    bool found = false;
    for (size_t i = 0; i < relays.size(); i++) {
        if (relays[i].contactGroups == groups) {
            cout << "Relay #" << (i + 1)
                 << " -> Voltage: " << relays[i].coilVoltage << " V"
                 << ", Current: " << relays[i].maxSwitchCurrent << " A"
                 << ", Groups: " << relays[i].contactGroups << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No relays found matching the condition." << endl;
    }
}

