//
// Created by Tom Goring on 06/12/2018.
//

#include <stdexcept>
#include <iostream>
#include "Vector.h"

Vector::Vector(int s) {

    elem = new double[s];
    sz = s;
}

double& Vector::operator[](int i) {

    if (i < 0 || i > size() - 1) { // if array index given is out of range

        throw std::out_of_range("Vector::operator[]");
    }

    return elem[i];
}

int Vector::size() {

    return sz;
}


//tests accessing an out of range index of a vector class.
void TestVRangeException(Vector& v) {

    try {

        v[v.size()] = 7;
    }
    catch (std::out_of_range) {

        std::cout<<"Given index is out of range.";
    }
}