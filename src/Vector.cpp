//
// Created by Tom Goring on 06/12/2018.
//
// Simple implementation of a vector struct - will be expanded later.
//

#include <iostream>

double read_and_sum(int s);

class Vector {

public:
    Vector(int s) :elem{new double[s]}, sz{s} { } // constructor
    double& operator[](int i) { return elem[i]; } // subscript function that returns a reference to the given element
                                                  // allows for you to check given indexes and such
    int size() { return sz; }

private:
    double *elem;
    int sz;
};

int test_Vector1(int argc, char **argv) {

    std::cout<<read_and_sum(3);
}

double read_and_sum(int s) {

    Vector v(s);

    for (int i = 0; i != v.size(); ++i) {

        std::cin>>v[i];
    }

    double sum = 0;

    for (int i = 0; i < v.size(); ++i) {

        sum += v[i];
    }

    return sum;
}