#include <iostream>
#include <iomanip>

using namespace std;

const int SIZE = 4;

long a = 100;
int b = 7;
short c = 3;
double d = 2.5;

enum DataType { TYPE_SHORT = 0, TYPE_INT = 1, TYPE_LONG = 2, TYPE_DOUBLE = 3 };

struct data_t {
    void* values[SIZE];
    DataType types[SIZE];
};

void print_data(const data_t* data_ptr) {

    for (int i = 0; i < SIZE; i++) {

        switch (data_ptr->types[i]) {

            case TYPE_SHORT:
                cout << "Short  " << *(static_cast<short*>(data_ptr->values[i])) << "\n";
                break;

            case TYPE_INT:
                cout << "Int    " << *(static_cast<int*>(data_ptr->values[i])) << "\n";
                break;

            case TYPE_LONG:
                cout << "Long   " << *(static_cast<long*>(data_ptr->values[i])) << "\n";
                break;

            case TYPE_DOUBLE:
                cout << "Double " << *(static_cast<double*>(data_ptr->values[i])) << "\n";
                break;
        }
    }

    cout << "\n";
}

int main() {

    data_t mydata;

    // Кожен values[i] відповідає своєму типу в types[i]
    mydata.values[0] = &a; // long a = 100
    mydata.values[1] = &b; // int b = 8
    mydata.values[2] = &c; // short c = 3
    mydata.values[3] = &d; // double d = 2.5

    mydata.types[0] = TYPE_LONG;
    mydata.types[1] = TYPE_INT;
    mydata.types[2] = TYPE_SHORT;
    mydata.types[3] = TYPE_DOUBLE;

    print_data(&mydata);

    // Неявне
    double implicit_result = a / (b + c) * d;

    // Явне
    double explicit_result = static_cast<double>(a) / (b + c) * d;

    cout << fixed << setprecision(3);

    cout << "Неявне перетворення :     " << implicit_result << "\n";
    cout << "Явне перетворення :    " << explicit_result << "\n";

    return 0;
}