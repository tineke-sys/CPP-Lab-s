#include <iostream>
#include <memory>
#include "RadioRelayExceptions.h"
#include "RadioRelay.h"
#include "ElectromagneticRelay.h"
#include "SolidStateRelay.h"
#include "RelayManager.h"

using namespace std;

// Helper to demonstrate stack unwinding
void triggerStackUnwind(double badVoltage) {
    RadioRelay r("Test", 12.0, 5.0, 1);
    r.setCoilVoltage(badVoltage); // throws InvalidDataException
}

int main() {
    cout << "=== Lab 13: Files & Exceptions (Variant 11: Radio Relay) ===\n\n";

    // 1. Polymorphism & Dynamic Vector
    cout << "[1] Adding relays to manager:\n";
    RelayManager manager;
    manager.addRelay(make_shared<RadioRelay>("RES-9", 12.0, 3.0, 2));
    manager.addRelay(make_shared<ElectromagneticRelay>("RP-4", 24.0, 10.0, 4, 500.0));
    manager.addRelay(make_shared<ElectromagneticRelay>("REM-12", 5.0, 1.5, 1, 120.0));
    manager.addRelay(make_shared<SolidStateRelay>("SSR-40DA", 32.0, 40.0, 1, 4000.0));
    manager.printAll();

    // 2. Overloaded Operators: <= sort, ==, []
    cout << "\n[2] Sorting by max current (operator<=):\n";
    manager.sortByCurrent();
    manager.printAll();

    cout << "\nOperator== test: "
         << (manager[0] == manager[0] ? "Equal (true)" : "Not equal (false)") << "\n";

    // 3. Bidirectional File I/O (std::fstream)
    const string filename = "relays.txt";
    cout << "\n[3] File I/O via std::fstream:\n";
    manager.saveToFile(filename);
    cout << "Saved " << manager.size() << " records to " << filename << "\n";

    RelayManager loadedManager;
    loadedManager.loadFromFile(filename);
    cout << "Loaded " << loadedManager.size() << " records from " << filename << "\n";

    // 4. Exception handling tests
    cout << "\n[4] Exception handling tests:\n";

    // 4.1 Index out of bounds (operator[])
    try {
        cout << "- Test operator[] index 99: ";
        RadioRelay& r = manager[99];
        (void)r;
    } catch (const IndexOutOfBoundsException& e) {
        cout << "Caught: " << e.what() << "\n";
    }

    // 4.2 Invalid data validation
    try {
        cout << "- Test invalid voltage (-5V): ";
        RadioRelay bad("Bad", -5.0, 1.0, 1);
    } catch (const InvalidDataException& e) {
        cout << "Caught: " << e.what() << "\n";
    }

    // 4.3 Missing file error
    try {
        cout << "- Test missing file: ";
        RelayManager m;
        m.loadFromFile("non_existent_file.txt");
    } catch (const FileException& e) {
        cout << "Caught: " << e.what() << "\n";
    }

    // 4.4 Stack unwinding
    try {
        cout << "- Test stack unwinding: ";
        triggerStackUnwind(-50.0);
    } catch (const RelayException& e) {
        cout << "Caught from unwound stack: " << e.what() << "\n";
    }

    cout << "\nAll tests completed successfully.\n";
    return 0;
}
