//
// Author: Andrzej Pomirski
//

#include "real_main.h"

#include <iostream>
using namespace std;

class VectorNd {
    double *_numbers;
    int size;
public:
    VectorNd() {
        this->_numbers = new double[0];
        this->size = 0;
    }

    VectorNd(const double numbers[], int size) {
        this->_numbers = new double[size];
        this->size = size;

        for (int i = 0; i < size; ++i) {
            this->_numbers[i] = numbers[i];
        }

        cout << "Traditional constructor!" << endl;
    }

    VectorNd(const VectorNd& original) {
        this->_numbers = new double[original.size];
        this->size = original.size;

        for (int i = 0; i < size; ++i) {
            this->_numbers[i] = original._numbers[i];
        }

        cout << "Copying constructor!" << endl;
    }

    ~VectorNd() {
        cout << "Freeing memory with address: " << _numbers << endl;
        delete[] _numbers;
    }

    VectorNd& operator=(const VectorNd& right) {
        if (this->size != right.size) {
            delete[] _numbers;

            this->_numbers = new double[right.size];
            this->size = right.size;
        }

        for (int i = 0; i < size; ++i) {
            this->_numbers[i] = right._numbers[i];
        }

        return *this;
    }

    double getNumber(int index) {
        return _numbers[index];
    }

    int getDimension() {
        return size;
    }

    void fillArray(double numbers[]) {
        for (int i = 0; i < size; ++i) {
            numbers[i] = _numbers[i];
        }
    }

    void setValue(double number, int index) {
        _numbers[index] = number;
    }

    void print(ostream& out = cout) {
        cout << "|------------------------------|" << endl;
        cout << "Vector address: " << this << endl;
        int dimension = this->getDimension();
        cout << "Dimension: " << dimension << endl;
        cout << "Elements:" << endl;

        for (int i = 0; i < dimension; ++i) {
            cout << "[" << i << "] = \t" << this->getNumber(i) << endl;
        }

        cout << "|------------------------------|" << endl;
    }
};

class VectorOfVectors {
    VectorNd *vectors;
    int size;
public:
    VectorOfVectors(const VectorNd vectors[], int size) {
        this->vectors = new VectorNd[size];
        this->size = size;

        for (int i = 0; i < size; ++i) {
            this->vectors[i] = vectors[i];
        }
    }

    friend istream& operator>>(istream& in, VectorOfVectors vov) {

    }
};

int main() {
    return 0;
}