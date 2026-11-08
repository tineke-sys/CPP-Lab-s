#include <iostream>
#include <vector>
#include "Rectangle.h"

using namespace std;

// Selection sort using overloaded <= operator
void sortRectanglesByArea(vector<Rectangle>& list) {
    for (size_t i = 0; i < list.size(); ++i) {
        size_t minIdx = i;
        for (size_t j = i + 1; j < list.size(); ++j) {
            if (list[j] <= list[minIdx]) {
                minIdx = j;
            }
        }
        if (minIdx != i) {
            Rectangle temp = list[i];
            list[i] = list[minIdx];
            list[minIdx] = temp;
        }
    }
}

int main() {
    cout << "========================================================" << endl;
    cout << "  Laboratory Work #12: Operator Overloading             " << endl;
    cout << "  Variant 11: Rectangle (Area <= and side -=)           " << endl;
    cout << "========================================================\n" << endl;

    // 1. Initial list of rectangles
    vector<Rectangle> rects;
    rects.push_back(Rectangle("Rect-A1", 12.0, 5.0));
    rects.push_back(Rectangle("Rect-A2", 3.0, 4.0));
    rects.push_back(Rectangle("Rect-B1", 8.0, 7.0));
    rects.push_back(Rectangle("Rect-B2", 6.0, 2.5));
    rects.push_back(Rectangle("Rect-B3", 10.0, 10.0));

    cout << "--- 1. Initial Rectangles ---" << endl;
    for (const auto& r : rects) {
        cout << r << endl;
    }

    // 2. Sort array by area using operator<=
    cout << "\n--- 2. Sorted Rectangles (Ascending Area) ---" << endl;
    sortRectanglesByArea(rects);
    for (const auto& r : rects) {
        cout << r << endl;
    }

    // 3. Decrease dimensions for each rectangle using operator-=
    const double decreaseValue = 2.0;
    cout << "\n--- 3. Decreasing Dimensions by " << decreaseValue << " via operator-= ---" << endl;
    for (auto& r : rects) {
        r -= decreaseValue;
    }

    for (const auto& r : rects) {
        cout << r << endl;
    }

    // 4. Comparison demo between two specific objects
    cout << "\n--- 4. Direct Operator Comparison Demo ---" << endl;
    if (rects[0] <= rects[1]) {
        cout << rects[0].getName() << " area is <= " << rects[1].getName() << " area" << endl;
    } else {
        cout << rects[0].getName() << " area is > " << rects[1].getName() << " area" << endl;
    }

    cout << "\nProgram completed successfully." << endl;
    return 0;
}

