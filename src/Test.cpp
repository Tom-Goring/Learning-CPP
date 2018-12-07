//
// Created by Tom Goring on 07/12/2018.
//

#include <stdexcept>
#include <iostream>
#include "Vector.h"
#include "math.h"

double sqrt_sum(Vector& v);

int main(int argc, char **argv) {

    try {

        Vector v(-17);
    }
    catch (std::length_error) {

        std::cout<<"Length error.\n";
    }
    catch (std::bad_alloc& err) {

        std::cout<<"Bad alloc.\n";
    }


}