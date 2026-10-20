#include <iostream>
#include "RadioRelay.h"

using namespace std;

int main() {

    cout << "=== Default Constructor (empty list) ===" << endl;
    RadioRelayList emptyList;
    emptyList.printData();
    emptyList.printByMinCurrent(5.0);   // порожній список - буде повідомлення

    cout << "\n=== Constructor with parameters ===" << endl;
    RadioRelayList paramList(12.0, 10.0, 2);
    paramList.printData();

    cout << "\n=== Input from User ===" << endl;
    RadioRelayList myList;
    myList.inputData();
    myList.printData();

    cout << "\n=== Add relays + validation test ===" << endl;
    RadioRelayList testList;
    testList.addRelay(24.0, 5.0, 1);
    testList.addRelay(12.0, 16.0, 4);
    testList.addRelay(220.0, 30.0, 2);
    testList.addRelay(-5.0, 10.0, 2);     // некоректна напруга
    testList.addRelay(24.0, 500.0, 2);    // некоректний струм
    testList.addRelay(24.0, 10.0, 20);    // некоректна кількість груп
    testList.printData();

    cout << "\n=== Setters (valid and invalid) ===" << endl;
    testList.setCoilVoltage(1, 48.0);     // коректно
    testList.setMaxSwitchCurrent(2, 20.0);// коректно
    testList.setContactGroups(3, 0);      // некоректно
    testList.setCoilVoltage(9, 12.0);     // неіснуючий номер реле
    testList.printData();

    cout << "\n=== Search by criteria ===" << endl;
    testList.printByMinCurrent(15.0);     // знайдеться
    testList.printByMinCurrent(80.0);     // нічого не знайдеться
    testList.printByContactGroups(2);     // знайдеться
    testList.printByContactGroups(7);     // нічого не знайдеться

    cout << "\n=== Array overflow test ===" << endl;
    RadioRelayList fullList;
    for (int i = 0; i < 6; i++) {         // масив на 5 елементів, 6-й не влізе
        fullList.addRelay(12.0, 5.0, 1);
    }
    fullList.printData();

    cout << "\n=== End of program ===" << endl;
    return 0;
}
