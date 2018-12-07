//
// Created by Tom Goring on 06/12/2018.
//

#include <stdexcept>
#include <iostream>

#ifndef EXERCISES_VECTOR_H
#include "BasicVector.h"
#endif

BasicVector::BasicVector(int s) {

    if (s < 0) {

        throw std::length_error("BasicVector constructor: negative size");
    } // if given length is invalid throw exception
    elem = new double[s];
    sz = s;

    for (int i = 0; i != s; ++i) {

        elem[i] = 0;
    }
}

BasicVector::~BasicVector() {

    delete[] elem;
}

double& BasicVector::operator[](int i) {

    if (i < 0 || i > size() - 1) { // if array index given is out of range

        throw std::out_of_range("BasicVector::operator[]");
    }

    return elem[i];
}

int BasicVector::size() {

    return sz;
}

//tests accessing an out of range index of a vector class.
void TestVRangeException(BasicVector& v) {

    try {

        v[v.size()] = 7;
    }
    catch (std::out_of_range) {

        std::cout<<"Given index is out of range.";
    }
}

void TestVectorConstructor() {

        try {

            BasicVector v(-17);
        }
        catch (std::length_error&) {

            std::cout<<"Length error.\n";
        }
        catch (std::bad_alloc& err) {

            std::cout<<"Bad alloc.\n";
        }
};