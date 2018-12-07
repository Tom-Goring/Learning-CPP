//
// Created by Tom Goring on 07/12/2018.
//

#ifndef EXERCISES_CONVERSION_H
#define EXERCISES_CONVERSION_H

#endif //EXERCISES_CONVERSION_H

#include <iostream>
#include <algorithm> // for reversal of string
#include <sstream>

typedef long long number; // so I don't have to keep typing "long long".

number BinaryToDecimal(std::string binary);
std::string DecimalToBinary(number decimal);
void BinDecMenu();