#include <iostream>
using namespace std;


class Vehicle {
protected:
    string brand;
    int year;

public:
    Vehicle(string b, int y) {
        brand = b;
        year = y;
    }

    virtual void showInfo() {
        cout << "Brand: " << brand << endl;
        cout << "Year: " << year << endl;
    }

    virtual void startEngine() {
        cout << "Starting engine of Vehicle" << endl;
    }

    virtual ~Vehicle() {}
};


class Car : public Vehicle {
private:
    int numDoors;

public:
    Car(string b, int y, int d) : Vehicle(b, y) {
        numDoors = d;
    }

    void showInfo() override {
        cout << "Brand: " << brand << endl;
        cout << "Year: " << year << endl;
        cout << "Number of doors: " << numDoors << endl;
    }

    void startEngine() override {
        cout << "Car engine is starting!" << endl;
    }

    virtual ~Car() {}
};


class ElectricCar : public Car {
private:
    int batteryCapacity; // in kWh

public:
    
    ElectricCar() : Car("Nissan", 2022, 4) {
        batteryCapacity = 40;
    }


    ElectricCar(string b, int y, int d, int bc) : Car(b, y, d) {
        batteryCapacity = bc;
    }

    void showInfo() override {
        Car::showInfo();
        cout << "Battery Capacity: " << batteryCapacity << " kWh" << endl;
    }

    void startEngine() override {
        cout << "Electric engine is starting... Silent but powerful!" << endl;
    }

    ~ElectricCar() {}
};

int main() {
    
    Vehicle* v = new Vehicle("Generic", 2015);
    v->showInfo();
    v->startEngine();
    delete v;

    
    Car* c = new Car("Toyota", 2021, 4);
    c->showInfo();
    c->startEngine();
    delete c;

    
    ElectricCar* e1 = new ElectricCar("Tesla", 2023, 4, 75);
    e1->showInfo();
    e1->startEngine();
    delete e1;

   constructor
    ElectricCar* e2 = new ElectricCar();
    e2->showInfo();
    e2->startEngine();
    delete e2;

    return 0;
}
