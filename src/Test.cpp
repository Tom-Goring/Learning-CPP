//
// Created by Tom Goring on 07/12/2018.
//

#include <iostream>
#include <vector>
#include "Collatz.h"

int main(int argc, char **argv) {

    std::vector<collatz_mapping> v;
    int runs = 50;

    for (int i = 0; i < runs; ++i) {

        v.push_back(collatz(i));
    }

    for (int i = 0; i < runs; ++i) {

        std::cout << v[i].steps << std::endl;
    }
}