//
// Created by Tom Goring on 16/12/2018.
//

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

string compressString(string input);

int main() {

    cout.flush();

    string input = "aabcccccaaa";

    string compressedInput = compressString(input);

    cout << compressedInput << endl;
}

string compressString(string input) {

    string compressedString;
    int indexOfString = 0;

    while (indexOfString != input.length()) {

        int numberOfChar = 0;

        char currentChar = input[indexOfString];

        while (input[indexOfString] == currentChar) {

            numberOfChar++;
            indexOfString++;
        }

        compressedString += currentChar;
        compressedString += std::to_string(numberOfChar);
    }

    return compressedString;
}

