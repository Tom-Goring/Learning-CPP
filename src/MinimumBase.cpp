//
// Created by tomgo on 13/12/2018.
//

#include <iostream>
using namespace std;

bool ispalindrome(const string string);
string convertToBase(int number, int base);

// To execute C++, please define "int main()"
int main() {

    bool success = false;
    int base = 2;
    string number;
    int input;

    cout << "Enter a number to find the minimum base for a palindrome: ";
    cin >> input;

    while (!success) {

        number = convertToBase(input, base);

        if (ispalindrome(number)){

            cout << "Minimum base is: " << base << endl;
            cout << input << " is " << number << " in base " << base << endl;
            success = true;
        }
        else {

            base++;
        }
    }
}

bool ispalindrome(const string string) {

    for (unsigned i = 0; i < string.length(); i++) {

        if (string[i] != string[string.length() - 1 - i]) {

            return false;
        }
    }

    return true;
}

string convertToBase(int number, int base) {

    string str;

    while (number) {

        int digit = number % base;
        number /= base;
        str.push_back(digit + '0');
    }

    return str;
}

