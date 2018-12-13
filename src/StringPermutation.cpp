//
// Created by Tom Goring on 13/12/2018.
//

#include <iostream>
#include <unordered_map>
#include <algorithm>

bool isPermutation(std::string string1, std::string string2);

int main() {

    std::string string1 = "hello";
    std::string string2 = "ollexh";

    if (isPermutation(string1, string2)) {

        std::cout << string1 << " is a permutation of " << string2 << std::endl;
    }
    else {

        std::cout << string1 << " is not a permutation of " << string2 << std::endl;
    }
}

bool isPermutation(std::string string1, std::string string2) {

    if (string1.length() != string2.length()) {

        return false;
    }

    std::sort(string1.begin(), string1.end());
    std::sort(string2.begin(), string2.end());

    return (string1 == string2);
}