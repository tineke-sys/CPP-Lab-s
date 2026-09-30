#include <iostream>
#include "RadioRelay.h"

using namespace std;

void printRelayByValue(RadioRelay r) {
    cout << "\n[By Value function call]";
    r.printData();
}

void upgradeRelayCurrent(RadioRelay& r, double newCurrent) {
    cout << "\n[By Reference function: updating max switching current...]" << endl;
    r.setMaxSwitchCurrent(newCurrent);
}

int main() {

    cout << "=== Default Constructor ===" << endl;
    RadioRelay defaultRelay;
    defaultRelay.printData();

    cout << "\n";

    cout << "=== Input from User ===" << endl;
    RadioRelay myRelay;
    myRelay.inputData();
    myRelay.printData();

    cout << "\n";

    cout << "=== With Setters ===" << endl;
    RadioRelay optRelay;
    optRelay.setCoilVoltage(12.0);
    optRelay.setMaxSwitchCurrent(10.0);
    optRelay.setContactGroups(2);
    optRelay.printData();

    cout << "\n";

    cout << "=== Validation test (invalid values) ===" << endl;
    RadioRelay testRelay(24.0, 5.0, 1);
    testRelay.setCoilVoltage(-5.0);
    testRelay.setMaxSwitchCurrent(500.0);
    testRelay.setContactGroups(20);
    testRelay.printData();   // значення мають лишитись 24 В, 5 А, 1 група

    cout << "\n";

    cout << "=== Pass by value and reference ===" << endl;
    RadioRelay paramRelay(24.0, 16.0, 4);

    printRelayByValue(paramRelay);
    upgradeRelayCurrent(paramRelay, 20.0);

    cout << "\nAfter reference update:";
    paramRelay.printData();

    cout << "\n";

    cout << "=== Copy data ===" << endl;
    RadioRelay copyRelay;
    copyRelay.copyFrom(paramRelay);
    copyRelay.printData();

    cout << "\n=== End of program ===" << endl;
    return 0;
}
