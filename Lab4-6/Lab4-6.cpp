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
    
    public:
        ~Car(){
            cout << "Obj deleted" << endl;
        }
        
    public:
        void inputData() {
        string name, model;
        uint16_t hp;
        int fuelInput;

        cout << "Enter car name: ";
        cin >> name;
        setName(name);

        cout << "Enter model: ";
        cin >> model;
        setModel(model);

        cout << "Enter HP: ";
        cin >> hp;
        setHP(hp);

        cout << "Enter fuel type (0-PETROL, 1-DIESEL, 2-GAS, 3-ELECTRIC): ";
        cin >> fuelInput;
        setFuel(static_cast<uint16_t>(fuelInput));
    } 

    public:
        void disp(){



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
        if (fuel <= 3){
            FuelType = fuel;
        } else FuelType = 4;
    }
};

int main(){

    // name, model, hp, (0-petr,1-dies,2-gas,3-electr);
    Car myCar;

    myCar.inputData();

    return 0;
}