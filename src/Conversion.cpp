//
// Created by Tom Goring on 07/12/2018.
//

#include "Conversion.h"


number BinaryToDecimal(std::string binary) {

    std::reverse(binary.begin(), binary.end()); // so we can work out the multiples of 2 as we go rather than backwards
                                                // starting with the largest.

    number decimal = 0; // number being converted to
    number base = 1; // to multiply by 2

    for (int i = 0; i < binary.size(); ++i) {

        // if we hit a 1, add base (which will be 2^current element of string)
        if (binary[i] == '1') {

            decimal += base;
        }

        base *= 2;
    }

    return decimal;
}

std::string DecimalToBinary(number decimal) {

    std::stringstream binary;
    std::string result;

    while (decimal > 0) {

        binary << (decimal % 2);
        decimal /= 2;
    }

    result = binary.str();
    std::reverse(result.begin(), result.end());

    return result;
}

void BinDecMenu() {

    std::cout << "What do you want to do : \n"
                 "1. Binary to Decimal\n"
                 "2. Decimal to Binary\n"
                 "Enter choice: ";

    int choice;

    std::cin >> choice;

    switch(choice) {

        case 1: {

            std::cout << "Enter a Binary number: ";

            std::string input;

            std::cin >> input;

            std::cout << input << " is " << BinaryToDecimal(input) << " as a decimal.\n";

            break;
        }

        case 2: {

            std::cout << "Enter a Decimal number: ";

            number input;

            std::cin >> input;

            std::cout << input << " is " << DecimalToBinary(input) << " as a binary.\n";

            break;
        }

        default: {

            std::cout << "Exiting program.\n";
        }
    }
}