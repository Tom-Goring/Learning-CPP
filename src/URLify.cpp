//
// Created by Tom Goring on 13/12/2018.
//
// This could be more efficient if I were to use pointers instead of array indexes I think.
//

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

void URLify(string & string);
void replaceSpaces(string &string, int num_spaces);
int countSpaces(string &string);
int findIndexOfSpace(string &string);
void moveCharsBackFrom(string &string, int index_of_space);

int main() {

    cout.flush();

    string string = "Hello there my name is Tom";

    URLify(string);

    cout << string;
}

void URLify(string & string) {

    int num_spaces = countSpaces(string);

    string.resize(string.size() + num_spaces * 2);

    replaceSpaces(string, num_spaces);
}

void replaceSpaces(string &string, int num_spaces) {

    for (int space = 0; space < num_spaces; space++) {

        int index_of_space = findIndexOfSpace(string);

        moveCharsBackFrom(string, index_of_space);

        string[index_of_space + 1] = '%';
        string[index_of_space + 2] = '2';
        string[index_of_space + 3] = '0';
    }
}

int countSpaces(string &string) {

    int num_spaces = 0;

    for (char i : string) {

        if (i == ' ') {

            num_spaces++;
        }
    }

    return num_spaces;
}

int findIndexOfSpace(string &string) {

    bool space_found = false;
    int index_of_space = string.size();

    while(!space_found) {

        if (string[index_of_space] == ' ') {

            space_found = true;
        }

        index_of_space--;
    }

    return index_of_space;
}

void moveCharsBackFrom(string &string, int index_of_space) {

    for (int i = string.size(); i > index_of_space; i--) {

        if (string[i] != '\0') {

            string[i + 2] = string[i];
        }
    }
}