//
// Author: Andrzej Pomirski
//

#ifndef LAB1_COMPLEX_H
#define LAB1_COMPLEX_H

#include "number_value.h"

class Complex : public Numerical_Value {
protected:
    double real;
    double imaginary;
public:
    Complex(double real = 0, double imaginary = 0);
    ~Complex();
    Complex operator+(Complex &);
    virtual double module();

    friend std::ostream &operator<<(std::ostream &out, Complex &number);
    void print(std::ostream &out) {
        out << *this;
    }
};

class Even_More_Complex : public Complex {
public:
    Even_More_Complex(int integer);
    double module();

    friend std::ostream &operator<<(std::ostream &out, Even_More_Complex &number);
};
#endif //LAB1_COMPLEX_H
