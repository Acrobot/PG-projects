//
// Author: Andrzej Pomirski
//

#ifndef LAB1_NUMBER_VALUE_H
#define LAB1_NUMBER_VALUE_H

#include <iostream>

class Numerical_Value {
public:
    virtual double module() = 0;
    virtual void print(std::ostream &out) = 0;
    virtual ~Numerical_Value() {}
};

#endif //LAB1_NUMBER_VALUE_H
