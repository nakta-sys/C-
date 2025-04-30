#include <iostream>
#include <string>
using namespace std;

class Car {
private:
    string model;
    int year;
    double price;

public:
    Car(string m, int y, double p) : model(m), year(y), price(p) {
        cout << "Car Constructor: " << model << " (" << year << ") - $" << price << endl;
    }

    ~Car() {
        cout << "Car Destructor: " << model << " destroyed" << endl;
    }

    void display() const {
        cout << "Model: " << model << ", Year: " << year << ", Price: $" << price << endl;
    }
};

class CarCollection {
private:
    Car** cars;
    int size;

public:
    CarCollection() {
        cout << "How many cars do you want to enter? ";
        cin >> size;
        cars = new Car*[size];

        for (int i = 0; i < size; ++i) {
            string model;
            int year;
            double price;

            cout << "\nEnter model for car " << i + 1 << ": ";
            cin.ignore();
            getline(cin, model);
            cout << "Enter year: ";
            cin >> year;
            cout << "Enter price: ";
            cin >> price;

            cars[i] = new Car(model, year, price); // use parameterized constructor here
        }

        cout << "\nCarCollection initialized with " << size << " cars\n";
    }

    ~CarCollection() {
        for (int i = size - 1; i >= 0; --i) {
            delete cars[i];
        }
        delete[] cars;
        cout << "CarCollection destroyed" << endl;
    }

    void displayCars() const {
        cout << "\n--- Car Collection ---\n";
        for (int i = 0; i < size; ++i) {
            cars[i]->display();
        }
    }
};

int main() {
    {
        CarCollection collection;
        collection.displayCars();
    } 

    return 0;
}
