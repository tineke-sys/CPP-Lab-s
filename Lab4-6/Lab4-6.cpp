#include <iostream>
#include <string>
#include <cstdint>

using namespace std;

class Car{

    public:
        enum fueltype{PETROL = 0, DIESEL = 1, GAS = 2, ELECTRIC = 3, UNKNOWN = 4};

    private:
        string Name;
        string Model;
        uint16_t HP;
        uint8_t FuelType;

    public:
        Car(){
            Name = "-";
            Model = "-";
            HP = 0;
            FuelType = 0;
        }    

    public:
        Car(string name, string model, uint16_t hp, uint8_t fuel){
            Name = name;
            Model = model;
            setHP(hp);
            FuelType = fuel;
        }    

    ~Car(){
        cout << "Obj deleted" << endl;
    }
    
    void setName(string name){
        if(name.empty()){
            Name = "unknown";
        } else {
            Name = name;
        }
    }

    void setModel(string model){
        if(model.empty()){
            Model = "unknown";
        } else {
            Model = model;
        }
    }

    void setHP(uint16_t hp){
        if (hp >= 0){
            HP = hp;
        } else HP = 0;
    }

    void setFuel(uint16_t fuel){
        if (fuel >= 0 && fuel <= 3){
            FuelType = fuel;
        } else FuelType = 4;
    }
};

int main(){



    return 0;
}