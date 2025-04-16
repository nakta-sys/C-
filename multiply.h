#ifndef MULTIPLY_H
#define MULTIPLY_H

#include <cmath>

// (A) Multiply two integers
int multiply(int a, int b) {
    return a * b;
}

// (B) Multiply two doubles
double multiply(double a, double b) {
    return a * b;
}

// (C) Multiply an integer and a double; apply ceil/floor based on flag
int multiply(int a, double b, bool flag) {
    double result = a * b;
    return flag ? ceil(result) : floor(result);
}

#endif
