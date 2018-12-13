//
// Created by Tom Goring on 13/12/2018.
//

#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using std::string;
using std::cout;
using std::endl;
using std::tolower;

bool palindromesPossible(string input);
void isPalindromePermutation(string input);

int main() {

    // currently does not deal with upper and lower case letters.
    isPalindromePermutation("ABCCBA");
    isPalindromePermutation("Tact coa");
    isPalindromePermutation("tact coa");
}

void isPalindromePermutation(const string input) {

    if (palindromesPossible(input)) {

        cout << input << " is a permutation of a palindrome.\n";
    }
    else {

        cout << input << " is not a permutation of a palindrome.\n";
    }
}

bool palindromesPossible(string input) {

    std::unordered_map<char, int> charCounts;

    int num_spaces = 0;

    for (char i : input) {

        if (i != ' ') {

            charCounts[i]++;
        }
        else {

            num_spaces++;
        }
    }

    int num_odd = 0;

    for (auto i : charCounts) {

        if (i.second % 2 != 0) {

            num_odd++;
        }
    }

    unsigned long l = input.length() - num_spaces;

    // return true if length is odd and only 1 odd occurrence, or if length is even and there are no odd occurrences
    return (l % 2 == 1 && num_odd == 1) || (l % 2 == 0 && num_odd == 0);
}

