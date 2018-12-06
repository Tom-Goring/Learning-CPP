//
// Created by Tom Goring on 06/12/2018.
//

#include <iostream>

double square(double x);
void print_square(double x);

int main(int argc, char **argv) {

    print_square(2);
    print_square(3);
    print_square(4);
}

double square(double x) {

    return x * x;
}

void print_square(double x) {

    std::cout<<"The square of "<< x << " is " << square(x) << "\n";
}