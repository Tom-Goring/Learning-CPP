//
// Created by Tom Goring on 13/12/2018.
//

#include <iostream>
#include <unordered_map>

bool isUnique(std::string String);

int main() {

    std::string String = "aacdefg";

    if (isUnique(String)) {

        std::cout << String << " consists of unique characters." << std::endl;
    }
    else {

        std::cout << String << " consists of non-unique characters." << std::endl;
    }
}

bool isUnique(std::string String) {

    std::unordered_map<char, int> charMap;

    for (char i : String) {

        if (charMap[i] == 1) {

            return false;
        }

        charMap[i]++;
    }

    return true;
}