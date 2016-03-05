//
// Author: Andrzej Pomirski
//

#ifndef LAB1_NUMER_H
#define LAB1_NUMER_H

#include "number_value.h"

class Number : public Numerical_Value {
private:
    double real;
public:
    Number(double real);
    ~Number();
    Number operator+(Number &right) {
        return Number(this->real + right.real);
    }
    double module();
    friend std::ostream &operator<<(std::ostream &out, Number &number);
    void print(std::ostream &out) {
        out << *this;
    }
};

#endif //LAB1_NUMER_H
