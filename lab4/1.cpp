#include <iostream>
#include <cmath>

class Complex {
    double real{}, imag{};
public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    
    Complex operator+(const Complex& rhs) const {
        return {real + rhs.real, imag + rhs.imag};
    }
    Complex operator-(const Complex& rhs) const {
        return {real - rhs.real, imag - rhs.imag};
    }
    Complex operator/(const Complex& rhs) const {
        double denom = rhs.real * rhs.real + rhs.imag * rhs.imag;
        return {( real * rhs.real + imag * rhs.imag) / denom,
                ( imag * rhs.real - real * rhs.imag) / denom};
    }

    
    friend std::ostream& operator<<(std::ostream& os, const Complex& c) {
        os << c.real << (c.imag >= 0 ? " + " : " - ")
           << std::fabs(c.imag) << "i";
        return os;
    }
};

int main() {
    Complex c1(4, 5), c2(2, -3);

    std::cout << "c1 = " << c1 << '\n'
              << "c2 = " << c2 << '\n'
              << "Sum = " << c1 + c2 << '\n'
              << "Difference = " << c1 - c2 << '\n'
              << "Quotient = " << c1 / c2 << '\n';
    return 0;
}
