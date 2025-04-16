#include <iostream>
#include "multiply.h"

using namespace std;

int main() {
    int int1, int2;
    double double1, double2;
    bool flag;

    // Case A: Two integers
    cout << "Enter two integers: ";
    cin >> int1 >> int2;
    cout << "Product (integers): " << multiply(int1, int2) << endl;

    // Case B: Two doubles
    cout << "Enter two doubles: ";
    cin >> double1 >> double2;
    cout << "Product (doubles): " << multiply(double1, double2) << endl;

    // Case C: One integer, one double, and a flag
    cout << "Enter integer, double, and flag (1 for ceil, 0 for floor): ";
    cin >> int1 >> double1 >> flag;
    cout << "Product with flag: " << multiply(int1, double1, flag) << endl;

    return 0;
}