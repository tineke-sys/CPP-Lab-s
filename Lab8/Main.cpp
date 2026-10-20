#include <iostream>
#include <vector>
#include "RadioRelay.h"

using namespace std;

int main() {
    cout << "====================================================\n";
    cout << "     LAB 8: DYNAMIC ARRAYS (std::vector) DEMO       \n";
    cout << "     Variant 11: Radio Relay (RadioRelayList)       \n";
    cout << "====================================================\n";

    // 1. Конструктор за замовчуванням
    cout << "\n>>> 1. Testing Default Constructor (empty list):" << endl;
    RadioRelayList relayList;
    relayList.printData();

    // 2. Додавання елементів (додавання в кінець: push_back) та валідація
    cout << ">>> 2. Adding valid and invalid relays:" << endl;
    relayList.addRelay(12.0, 5.0, 2);     // Валідний
    relayList.addRelay(24.0, 16.0, 4);    // Валідний
    relayList.addRelay(220.0, 30.0, 1);   // Валідний
    relayList.addRelay(-12.0, 10.0, 2);   // Невалідна напруга
    relayList.addRelay(12.0, 250.0, 2);   // Невалідний струм (> 100 A)
    relayList.addRelay(24.0, 10.0, 15);   // Невалідна кількість груп (> 8)

    cout << "\nCurrent state after additions:" << endl;
    relayList.printData();

    // 3. Вставка елемента у довільну позицію (insert)
    cout << ">>> 3. Testing Insertion (insertRelay):" << endl;
    cout << "Inserting relay at position #2 (Voltage: 48V, Current: 8A, Groups: 2):" << endl;
    relayList.insertRelay(2, 48.0, 8.0, 2);
    relayList.printData();

    // Спроба вставки за невалідним індексом
    cout << "Attempting insert at invalid position #99:" << endl;
    relayList.insertRelay(99, 12.0, 5.0, 1);

    // 4. Сетери та перевірка валідності зміни полів
    cout << "\n>>> 4. Testing Setters with Validation:" << endl;
    relayList.setCoilVoltage(1, 15.5);       // Валідно
    relayList.setMaxSwitchCurrent(2, 12.0);   // Валідно
    relayList.setContactGroups(3, 99);       // Невалідно (попередження)
    relayList.printData();

    // 5. Вилучення елемента (erase)
    cout << ">>> 5. Testing Removal (removeRelay):" << endl;
    cout << "Removing relay at position #3:" << endl;
    relayList.removeRelay(3);
    relayList.printData();

    // 6. Обмін місцями двох елементів
    cout << ">>> 6. Testing Element Swap (swapRelays):" << endl;
    cout << "Swapping relay #1 and relay #2:" << endl;
    relayList.swapRelays(1, 2);
    relayList.printData();

    // 7. Пошук та фільтрація
    cout << ">>> 7. Testing Search and Filtering:" << endl;
    relayList.printByMinCurrent(10.0);
    relayList.printByContactGroups(4);

    // 8. Конструктор з ініціалізатором та обмін списками (vector::swap)
    cout << "\n>>> 8. Testing Second Object & List Swap (swapLists):" << endl;
    vector<relay_s_t> sampleData = {
        {5.0, 2.0, 1},
        {110.0, 40.0, 6}
    };
    RadioRelayList secondList(sampleData);
    cout << "Second list initially:" << endl;
    secondList.printData();

    cout << "Swapping first list and second list contents:" << endl;
    relayList.swapLists(secondList);

    cout << "First list after swap:" << endl;
    relayList.printData();
    cout << "Second list after swap:" << endl;
    secondList.printData();

    // 9. Очищення списку (clear)
    cout << ">>> 9. Testing Clear (clear):" << endl;
    relayList.clear();
    relayList.printData();

    cout << "\n>>> 10. End of main - Object Destruction:" << endl;
    return 0;
}

