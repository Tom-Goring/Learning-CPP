//
// Created by tomgo on 06/12/2018.
//
// Simple implementation of a vector struct - will be expanded later.
//

#include <iostream>

double read_and_sum(int s);

struct Vector {

    int sz;
    double *elem;
};

int main(int argc, char **argv) {

    std::cout<<read_and_sum(3);
}

// & in parameter passes by reference
void vector_init(Vector& v, int s) {

    v.elem = new double[s]; // new operator allocates memory from the heap
    v.sz = s;
}

double read_and_sum(int s) {

    Vector v;
    vector_init(v, s);

    for (int i = 0; i != s; i++) {

        std::cin>>v.elem[i];
    }

    double sum = 0;
    for (int i = 0; i != s; i++) {

        sum += v.elem[i];
    }

    return sum;
}