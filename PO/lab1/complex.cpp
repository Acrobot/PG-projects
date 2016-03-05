//
// Author: Andrzej Pomirski
//

#include "complex.h"
#include <cmath>

Complex::Complex(double real, double imaginary) {
    this->real = real;
    this->imaginary = imaginary;

    std::cout << "Constructor | Number = " << real << " + " << imaginary << "i" << std::endl;
}

Complex::~Complex() {
    std::cout << "Destructor | Number = " << real << " + " << imaginary << "i" << std::endl;
}

double Complex::module() {
    return sqrt(real * real + imaginary * imaginary);
}

Complex Complex::operator+(Complex &number) {
    return Complex(real + number.real, imaginary + number.imaginary);
}

std::ostream& operator<<(std::ostream &out, Complex &number) {
    out << "Complex number: " << number.real << " + " << number.imaginary << "i" << std::endl;
    return out;
}

Even_More_Complex::Even_More_Complex(int integer) : Complex(integer, 5) {};
double Even_More_Complex::module() {
    return Complex::module() * Complex::module();
}

std::ostream& operator<<(std::ostream &out, Even_More_Complex &number) {
    out << "Even more complex number module: " << number.module() << std::endl;
    return out;
}