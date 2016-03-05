#include "complex.h"
#include "number.h"

#include <iostream>

int main() {
    Number *number = new Number(5); //Number constructor
    Complex *complex = new Complex(5, 3); //Complex constructor

    //Printing:
    std::cout << *number << *complex << std::endl;

    //Adding:
    Complex *second_complex = new Complex(1, 2);
    Complex addition_result = *complex + *second_complex;

    delete(number); //Number destructor
    delete(complex); //Complex destructor
    delete(second_complex);

    Even_More_Complex even_more_complex(5);
    std::cout << even_more_complex << std::endl;

    Numerical_Value* values[] = {
            new Complex(5), //Theoretically leaks memory, I don't care ¯\_(ツ)_/¯
            new Complex(3, 2),
            new Number(6)
    };

    std::cout << "Modules: " << std::endl;

    for (Numerical_Value *value : values) {
        std::cout << value->module() << ", ";
    }

    std::cout << std::endl;

    return 0;
}