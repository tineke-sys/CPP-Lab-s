#include <iostream>
#include <iomanip>

using namespace std;

const int SIZE = 4;

long a = 100;
int b = 7;
short c = 3;
double d = 2.5;


struct data_t{ 
    void* values[SIZE]; 
    int types[SIZE];         
};

void print_data(struct data_t* data_ptr){

    for(int i = 0; i < SIZE; i++){
        
        switch (data_ptr->types[i]){

            case 0:            
                cout << "Short " << *(static_cast<short*>(data_ptr->values[i])) << "\n";
            break;

            case 1:            
                cout << "Int " << *(static_cast<int*>(data_ptr->values[i])) << "\n";
            break;

            case 2:            
                cout << "Long " << *(static_cast<long*>(data_ptr->values[i])) << "\n";
            break;

            case 3:            
                cout << "Double " << *(static_cast<double*>(data_ptr->values[i])) << "\n";
            break;

        }

    }

    cout << "\n";

}
    
int main(){

    struct data_t mydata;

    mydata.values[0] = &a; //long a 100
    mydata.values[1] = &b; //int b 7
    mydata.values[2] = &c; //shrt c 3
    mydata.values[3] = &d; //doub d 2.5

    mydata.types[0] = 2; //short
    mydata.types[1] = 1; //int 
    mydata.types[2] = 0; //long
    mydata.types[3] = 3; //double

    print_data(&mydata);

    double implict_result = (a / (b + c) * d);
    double exclipt_result = static_cast<double>(a / (b + c) * d);

    cout << fixed << setprecision(3);

    cout << "Не явне " << implict_result << "\n";
    cout << "Явне " << exclipt_result << "\n";

    return 0;
}