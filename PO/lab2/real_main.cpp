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

    ostream& print(ostream& out = cout) {
        cout << "|------------------------------|" << endl;
        cout << "Vector address: " << this << endl;
        int dimension = this->getDimension();
        cout << "Dimension: " << dimension << endl;
        cout << "Elements:" << endl;

        for (int i = 0; i < dimension; ++i) {
            cout << "[" << i << "] = \t" << this->getNumber(i) << endl;
        }

        cout << "|------------------------------|" << endl;
        return out;
    }

    friend ostream& operator<<(ostream& out, VectorNd &right) {
        return right.print(out);
    }
};

class VectorOfVectors {
    VectorNd *vectors;
    int size;
public:
    VectorOfVectors() {
        this->vectors = new VectorNd[0];
        this->size = 0;
    }

    VectorOfVectors(const VectorNd vectors[], int size) {
        this->vectors = new VectorNd[size];
        this->size = size;

        for (int i = 0; i < size; ++i) {
            this->vectors[i] = vectors[i];
        }
    }

    VectorOfVectors(const VectorOfVectors& vectorOfVectors) {
        this->vectors = new VectorNd[vectorOfVectors.size];
        this->size = vectorOfVectors.size;

        for (int i = 0; i < size; ++i) {
            this->vectors[i] = vectorOfVectors.vectors[i];
        }
    }

    VectorOfVectors operator=(const VectorOfVectors& vectorOfVectors) {
        VectorOfVectors copy(vectorOfVectors);

        std::swap(vectors, copy.vectors);
        std::swap(size, copy.size);

        return *this;
    }

    void add_vector(VectorNd &vector) {
        VectorNd *new_vectors = new VectorNd[this->size + 1];

        for (int i = 0; i < this->size; ++i) {
            new_vectors[i] = this->vectors[i];
        }

        new_vectors[this->size] = vector;

        delete[] this->vectors;

        this->size += 1;
        this->vectors = new_vectors;
    }

    friend istream& operator>>(istream& in, VectorOfVectors& vov) {
        int size = 0;
        in >> size;

        double numbers[size];

        for (int i = 0; i < size; ++i) {
            in >> numbers[i];
        }

        VectorNd *new_vector = new VectorNd(numbers, size);
        vov.add_vector(*new_vector);

        return in;
    }

    friend ostream& operator<<(ostream& out, VectorOfVectors& vov) {
        out << "Elements: " << vov.size << endl;
        for (int i = 0; i < vov.size; ++i) {
            out << "[" << i << "] = " << vov.vectors[i] << endl;
        }
    }
};

int main() {
    VectorOfVectors vectorOfVectors;

    cout << "Please type in the vector size and then its components" << endl;
    cin >> vectorOfVectors;
    cout << vectorOfVectors;

    VectorOfVectors vectorOfVectors2 = vectorOfVectors;
    cout << vectorOfVectors2;
    return 0;
}