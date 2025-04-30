#include <iostream>
#include <string>

void runWithCinIgnore() {
    std::cout << "\n--- Running WITH cin.ignore() ---\n";

    int age;
    std::string name;

    std::cout << "Enter your age: ";
    std::cin >> age;
    std::cin.ignore();  // This prevents getline() from reading leftover newline

    std::cout << "Enter your full name: ";
    std::getline(std::cin, name);

    std::cout << "\nOutput:\n";
    std::cout << "Name: " << name << "\nAge: " << age << "\n";
}

void runWithoutCinIgnore() {
    std::cout << "\n--- Running WITHOUT cin.ignore() ---\n";

    int age;
    std::string name;

    std::cout << "Enter your age: ";
    std::cin >> age;
    // No cin.ignore() here

    std::cout << "Enter your full name: ";
    std::getline(std::cin, name);  // This will likely read an empty line

    std::cout << "\nOutput:\n";
    std::cout << "Name: " << name << "\nAge: " << age << "\n";
}

int main() {
    std::cout << "Choose mode:\n";
    std::cout << "1. Use cin.ignore()\n";
    std::cout << "2. Do NOT use cin.ignore()\n";
    std::cout << "Enter choice (1 or 2): ";

    int choice;
    std::cin >> choice;

    if (choice == 1)
        runWithCinIgnore();
    else if (choice == 2)
        runWithoutCinIgnore();
    else
        std::cout << "Invalid choice.\n";

    return 0;
}
