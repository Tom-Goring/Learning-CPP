//
// Created by Tom Goring on 16/12/2018.
//

#define N 4

#include <iostream>

void cyclicRotate(int &a, int &b, int &c, int &d);
void rotateMatrix(int matrix[N][N]);
void printMatrix(int matrix[N][N]);

using std::cout;
using std::endl;

int main() {

    int matrix[N][N] = {
            { 1,1,1,2 },
            { 4,5,6,2 },
            { 4,8,7,2 },
            { 4,3,3,3 }
    };

    printMatrix(matrix);

    rotateMatrix(matrix);

    printMatrix(matrix);
}

// N = 2 needs 1
// N = 3 needs 2
// N = 4 needs 3
// N = 5 needs 4 -- so N - 1

void rotateMatrix(int matrix[N][N]) {

    for (int i = 0; i < N / 2; i++) {

        for (int j = 0; j < N - 1; j++) {

            cyclicRotate(matrix[i][j], matrix[j][N - 1 - i], matrix[N - 1- i][N - 1 - j], matrix[N - 1 - j][i]);
            printMatrix(matrix);
        }
    }
}

void cyclicRotate(int &a, int &b, int &c, int &d) {

   int temp = a;
   a = d;
   d = c;
   c = b;
   b = temp;
}

void printMatrix(int matrix[N][N]) {

    cout.flush();

    for (int i = 0; i < N; i++) {

        for (int j = 0; j < N; j++) {

            cout << " " << matrix[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
}
