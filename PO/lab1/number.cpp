//
// Author: Andrzej Pomirski
//

#include "number.h"

Number::Number(double real) {
    std::cout << "Constructor | Number = " << real << std::endl;

    this->real = real;
}

Number::~Number() {
    std::cout << "Destructor | Number = " << real << std::endl;
}

double Number::module() {
    return real < 0 ? -real : real;
}

std::ostream& operator<<(std::ostream &out, Number &number) {
    out << "Real number: " << number.real << std::endl;
    return out;
}