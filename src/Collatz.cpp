//
// Created by Tom Goring on 07/12/2018.
//

// Start with a number n > 1. Find the number of steps it takes to reach one using the following steps:
// If n is even: divide it by 2.
// If n is odd: multiply it by 3 and add one.
// Find how many steps it takes to reach one.

#include <iostream>
#include "Collatz.h"

collatz_mapping collatz(int n) {

    struct collatz_mapping m;
    m.n_value = n;

    while (n) {

        if (n == 1) {

            return m;
        }
        else if (n % 2 == 0) { // if n is even

            n /= 2;
        }
        else {

            (n *= 3)++; // multiply by 3 and add 1
        }
        m.steps++;
    }
}

void testCollatz(int n) {

    collatz_mapping m = collatz(n);

    std::cout<<n << " finishes in " << m.steps << std::endl;
}