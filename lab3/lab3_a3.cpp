#include <iostream>
using namespace std;

class Car {
private:
    string brand;
    int year;

public:
    Car(string b, int y) {
        brand = b;
        year = y;
        cout << "Car " << brand << " from " << year << " created." << endl;
    }

    ~Car() {
        cout << "Car " << brand << " destroyed." << endl;
    }

    void showInfo() {
        cout << "Brand: " << brand << endl;
        cout << "Year: " << year << endl;
    }
};

int main() {
    Car* myCar = new Car("Toyota", 2021);
    myCar->showInfo();
    delete myCar;

    return 0;
}
