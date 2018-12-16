//
// Created by Tom Goring on 16/12/2018.
//

#include <iostream>

using std::string;
using std::cout;

int lengthDifference(const string &string1, const string &string2);
bool isOneEditAway(const string &string1, const string &string2);


int main() {

    string string1 = "handle";
    string string2 = "handl";

    isOneEditAway(string1, string2) ? cout << "Is one edit away." : cout << "Is not one edit away.";
}

bool isOneEditAway(const string &string1, const string &string2) {

    int length1 = static_cast<int>(string1.length());
    int length2 = static_cast<int>(string2.length());

    int differenceInLength = abs(length1 - length2);

    if (differenceInLength > 1) {

        return false;
    }

    int num_edits = 0;

    int indexOfString1 = 0;
    int indexOfString2 = 0;

    while ( indexOfString1 < string1.length() && indexOfString2 < string2.length() ) {

        if (string1[indexOfString1] != string2[indexOfString2]) {

            // return false if we have already detected an edit
            if (num_edits == 1) {

                return false;
            }

            if (length1 > length2) { // if a char has been removed from string2

                indexOfString1++; // increment the char we're looking at in string1 so it's the equivalent in 2
            }
            else if (length1 < length2) { // if a char has been removed from string1

                indexOfString2++; // increment the char we're looking at in string2 so it's the equivalent in 1
            }
            else { // if a char has been changed

                indexOfString1++;
                indexOfString2++;
            }

            num_edits++;
        }
        else { // if both characters match we move on to the next couple

            indexOfString1++;
            indexOfString2++;
        }
    }

    // if we looped up to the length of a smaller string - add an edit for there being a char on the end of the larger
    if (indexOfString1 < string1.length() || indexOfString2 < string2.length()) {

        num_edits++;
    }

    return num_edits == 1; // true if num_edits is 1, false otherwise
}
