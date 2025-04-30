#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

class Car {
protected:
    std::string model;
    int year;
    double price;
public:
    virtual ~Car() = default;

    virtual void input() {
        std::cin.ignore(); // ensure getline works
        std::cout << "Enter model: "; std::getline(std::cin, model);
        std::cout << "Enter year: "; std::cin >> year;
        std::cout << "Enter price: "; std::cin >> price;
    }

    virtual void display() const = 0;
    virtual void destroyMessage() const = 0;
};

class ElectricCar : public Car {
    double batterySize;
public:
    void input() override {
        Car::input();
        std::cout << "Enter battery size (kWh): ";
        std::cin >> batterySize;
    }

    void display() const override {
        std::cout << "Model: " << model
                  << ", Year: " << year
                  << ", Price: $" << static_cast<int>(price)
                  << ", Battery: " << batterySize << " kWh\n";
    }

    void destroyMessage() const override {
        std::cout << "Destroying Electric Car: " << model << "\n";
    }

    ~ElectricCar() override = default;
};

class GasCar : public Car {
    double fuelCapacity;
public:
    void input() override {
        Car::input();
        std::cout << "Enter fuel capacity (L): ";
        std::cin >> fuelCapacity;
    }

    void display() const override {
        std::cout << "Model: " << model
                  << ", Year: " << year
                  << ", Price: $" << static_cast<int>(price)
                  << ", Fuel: " << fuelCapacity << " L\n";
    }

    void destroyMessage() const override {
        std::cout << "Destroying Gas Car: " << model << "\n";
    }

    ~GasCar() override = default;
};

class HybridCar : public Car {
    double batterySize, fuelCapacity;
public:
    void input() override {
        Car::input();
        std::cout << "Enter battery size (kWh): ";
        std::cin >> batterySize;
        std::cout << "Enter fuel capacity (L): ";
        std::cin >> fuelCapacity;
    }

    void display() const override {
        std::cout << "Model: " << model
                  << ", Year: " << year
                  << ", Price: $" << static_cast<int>(price)
                  << ", Battery: " << batterySize << " kWh"
                  << ", Fuel: " << fuelCapacity << " L\n";
    }

    void destroyMessage() const override {
        std::cout << "Destroying Hybrid Car: " << model << "\n";
    }

    ~HybridCar() override = default;
};

int main() {
    int n;
    std::cout << "Enter total number of cars: ";
    std::cin >> n;

    std::vector<Car*> fleet;

    for (int i = 0; i < n; ++i) {
        std::cout << "\nCar " << i + 1 << " type:\n"
                  << "[1] Electric\n"
                  << "[2] Gasoline\n"
                  << "[3] Hybrid\n"
                  << "Enter choice: ";
        int type;
        std::cin >> type;

        Car* car = nullptr;

        switch (type) {
            case 1: car = new ElectricCar(); break;
            case 2: car = new GasCar(); break;
            case 3: car = new HybridCar(); break;
            default: std::cout << "Invalid type, skipping...\n"; continue;
        }

        car->input();
        fleet.push_back(car);
    }

    std::cout << "\n--- Fleet Information ---\n";
    for (const auto& car : fleet)
        car->display();

    std::cout << "\n--- Cleaning up fleet ---\n";
    for (const auto& car : fleet) {
        car->destroyMessage();
        delete car;
    }

    return 0;
}
