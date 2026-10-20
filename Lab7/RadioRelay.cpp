#include "RadioRelay.h"
#include <limits>

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
    return index >= 1 && index <= count;
}

// ---------- Конструктори та деструктор ----------
RadioRelayList::RadioRelayList() {
    count = 0;
    // Заповнюємо весь масив нулями
    relays.fill({0.0, 0.0, 0});
}

RadioRelayList::RadioRelayList(double voltage, double current, int groups) {
    count = 0;
    relays.fill({0.0, 0.0, 0});
    addRelay(voltage, current, groups);
}

RadioRelayList::~RadioRelayList() {
    cout << "Obj deleted" << endl;
}

// ---------- Додавання ----------
bool RadioRelayList::addRelay(double voltage, double current, int groups) {
    if (count >= SIZE) {
        cout << "Array is full! Max " << SIZE << " relays." << endl;
        return false;
    }
    if (!isVoltageValid(voltage)) {
        cout << "Invalid coil voltage (" << voltage << " V)! Must be in (0, "
             << MAX_VOLTAGE << "]. Relay not added." << endl;
        return false;
    }
    if (!isCurrentValid(current)) {
        cout << "Invalid switching current (" << current << " A)! Must be in (0, "
             << MAX_CURRENT << "]. Relay not added." << endl;
        return false;
    }
    if (!isGroupsValid(groups)) {
        cout << "Invalid contact groups (" << groups << ")! Must be 1-"
             << MAX_GROUPS << ". Relay not added." << endl;
        return false;
    }

    relays[count].coilVoltage = voltage;
    relays[count].maxSwitchCurrent = current;
    relays[count].contactGroups = groups;
    count++;
    return true;
}

// ---------- Ввід ----------
void RadioRelayList::inputData() {
    int n;
    cout << "How many relays to enter (1-" << SIZE << ")? ";
    while (!(cin >> n) || n < 1 || n > SIZE) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input! Enter integer 1-" << SIZE << ": ";
    }

    for (int i = 0; i < n; i++) {
        double voltage, current;
        int groups;
        cout << "\nRelay #" << i + 1 << endl;

        cout << "Coil voltage (V): ";
        while (!(cin >> voltage)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Enter a number: ";
        }
        cout << "Max switching current (A): ";
        while (!(cin >> current)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Enter a number: ";
        }
        cout << "Contact groups: ";
        while (!(cin >> groups)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Enter an integer: ";
        }

        // Якщо дані некоректні - addRelay сам виведе попередження
        addRelay(voltage, current, groups);
    }
}

// ---------- Вивід ----------
void RadioRelayList::printData() const {
    cout << "\n--- Radio Relay List (" << count << "/" << SIZE << ") ---" << endl;
    if (count == 0) {
        cout << "List is empty." << endl;
    }
    for (int i = 0; i < count; i++) {
        cout << "#" << i + 1
             << " | Coil: " << relays[i].coilVoltage << " V"
             << " | Max current: " << relays[i].maxSwitchCurrent << " A"
             << " | Contact groups: " << relays[i].contactGroups << endl;
    }
    cout << "-----------------------------" << endl;
}

// ---------- Зміна полів ----------
void RadioRelayList::setCoilVoltage(int index, double voltage) {
    if (!isIndexValid(index)) {
        cout << "Invalid relay number (" << index << ")! Nothing changed." << endl;
        return;
    }
    if (!isVoltageValid(voltage)) {
        cout << "Invalid coil voltage (" << voltage << " V)! Must be in (0, "
             << MAX_VOLTAGE << "]. Value not changed." << endl;
        return;
    }
    relays[index - 1].coilVoltage = voltage;
}

void RadioRelayList::setMaxSwitchCurrent(int index, double current) {
    if (!isIndexValid(index)) {
        cout << "Invalid relay number (" << index << ")! Nothing changed." << endl;
        return;
    }
    if (!isCurrentValid(current)) {
        cout << "Invalid switching current (" << current << " A)! Must be in (0, "
             << MAX_CURRENT << "]. Value not changed." << endl;
        return;
    }
    relays[index - 1].maxSwitchCurrent = current;
}

void RadioRelayList::setContactGroups(int index, int groups) {
    if (!isIndexValid(index)) {
        cout << "Invalid relay number (" << index << ")! Nothing changed." << endl;
        return;
    }
    if (!isGroupsValid(groups)) {
        cout << "Invalid contact groups (" << groups << ")! Must be 1-"
             << MAX_GROUPS << ". Value not changed." << endl;
        return;
    }
    relays[index - 1].contactGroups = groups;
}

// ---------- Вивід за критерієм ----------
void RadioRelayList::printByMinCurrent(double minCurrent) const {
    cout << "\nRelays with max current >= " << minCurrent << " A:" << endl;
    bool found = false;
    for (int i = 0; i < count; i++) {
        if (relays[i].maxSwitchCurrent >= minCurrent) {
            cout << "#" << i + 1
                 << " | Coil: " << relays[i].coilVoltage << " V"
                 << " | Max current: " << relays[i].maxSwitchCurrent << " A"
                 << " | Contact groups: " << relays[i].contactGroups << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No relays found with this criterion." << endl;
    }
}

void RadioRelayList::printByContactGroups(int groups) const {
    cout << "\nRelays with " << groups << " contact group(s):" << endl;
    bool found = false;
    for (int i = 0; i < count; i++) {
        if (relays[i].contactGroups == groups) {
            cout << "#" << i + 1
                 << " | Coil: " << relays[i].coilVoltage << " V"
                 << " | Max current: " << relays[i].maxSwitchCurrent << " A"
                 << " | Contact groups: " << relays[i].contactGroups << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No relays found with this criterion." << endl;
    }
}

int RadioRelayList::getCount() const {
    return count;
}
