//
// Created by Tom Goring on 06/12/2018.
//

#include <iostream>

double square(double x);
void print_square(double x);

double square(double x) {

    return x * x;
}

void print_square(double x) {

    std::cout<<"The square of "<< x << " is " << square(x) << "\n";
}