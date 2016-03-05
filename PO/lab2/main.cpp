#include <iostream>

using namespace std;

class Vector3d {
    double _numbers[3];
public:
    Vector3d(double x1, double x2, double x3) {
        _numbers[0] = x1;
        _numbers[1] = x2;
        _numbers[2] = x3;
    }

    void fillArray(double numbers[]) {
        numbers[0] = _numbers[0];
        numbers[1] = _numbers[1];
        numbers[2] = _numbers[2];
    }
};

class VectorNd {
    double *_numbers;
    int size;
public:
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

void print(double array[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << array[i] << '\t';
    }
    cout << endl;
}

void printV1(VectorNd copiedVector) {
    cout << "|------------------------------|" << endl;
    cout << "Vector address: " << &copiedVector << endl;
    int dimension = copiedVector.getDimension();
    cout << "Dimension: " << dimension << endl;
    cout << "Elements:" << endl;

    for (int i = 0; i < dimension; ++i) {
        cout << "[" << i << "] = \t" << copiedVector.getNumber(i) << endl;
    }

    cout << "|------------------------------|" << endl;
}

void printV2(VectorNd &copiedVector) {
    cout << "|------------------------------|" << endl;
    cout << "Vector address: " << &copiedVector << endl;
    int dimension = copiedVector.getDimension();
    cout << "Dimension: " << dimension << endl;
    cout << "Elements:" << endl;

    for (int i = 0; i < dimension; ++i) {
        cout << "[" << i << "] = \t" << copiedVector.getNumber(i) << endl;
    }

    cout << "|------------------------------|" << endl;
}

int __main() {
    Vector3d v1(1, 2, 3);
    cout << sizeof v1 << endl;
    Vector3d v2(4, 5, 6);

    Vector3d v1Copy1(v1);
    Vector3d v1Copy2 = v1;

    double array[3];
    v1.fillArray(array);
    print(array, 3);

    v2.fillArray(array);
    print(array, 3);

    v1 = v2;

    v1.fillArray(array);
    print(array, 3);

    v1Copy1.fillArray(array);
    print(array, 3);

    v1Copy2.fillArray(array);
    print(array, 3);

    //Part two
    cout << endl << endl << endl;

    const double values[] = {1, 2, 3};
    VectorNd vnd1(values, 3);
    cout << sizeof(vnd1) << endl;

    vnd1.fillArray(array);
    print(array, 3);

    //Part 3
    cout << endl << endl << endl;

    const double values2[] = {4, 5, 6};
    VectorNd vnd2(values2, 3);

    vnd2.fillArray(array);
    print(array, 3);

    vnd1 = vnd2;

    vnd1.fillArray(array);
    print(array, 3);

    vnd2.fillArray(array);
    print(array, 3);

    vnd1.setValue(100.0, 0);
    vnd1.fillArray(array);
    print(array, 3);

    vnd2.fillArray(array);
    print(array, 3);

    //Part 4
    cout << endl << endl << endl;

    cout << "V1: " << endl;
    printV1(vnd2);
    cout << "V2: " << endl;
    printV2(vnd2);

    //Part 5
    cout << endl << endl << endl;

    vnd2.print();
    vnd1.print(cerr);

    return 0;
}