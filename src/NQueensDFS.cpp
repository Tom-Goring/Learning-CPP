//
// Created by Tom Goring on 08/12/2018.
//

#include "NQueensDFS.h"
#include <vector>
#include <iostream>

candidateSolution workingCandidate;
std::vector<candidateSolution> openList;

int main(int argc, char **argv) {

    printCandidateSolution(workingCandidate);
    std::cout<<calculateNumberOfQueensUnderAttack(workingCandidate);
}

int calculateNumberOfQueensUnderAttack(candidateSolution candidateToTest) {

    int vulnerableQueens = 0;

    for (int attackingQueen = 0; attackingQueen < candidateToTest.size - 1; attackingQueen++) {

        for (int defendingQueen = 0; defendingQueen < attackingQueen + 1; defendingQueen++) {

            // if queens are in same column
            if (candidateToTest.board[attackingQueen] == candidateToTest.board[defendingQueen]) {

                vulnerableQueens++;
            }

            if ((attackingQueen - defendingQueen) ==
                candidateToTest.board[attackingQueen] - candidateToTest.board[defendingQueen]) {

                vulnerableQueens++;
            }

            if (attackingQueen - defendingQueen ==
                (candidateToTest.board[defendingQueen] - candidateToTest.board[attackingQueen])) {

                vulnerableQueens++;
            }

        }
    }
}

void printCandidateSolution(candidateSolution candidateSolution) {

    // Print upper border of row
    for (int i = 0; i < N; ++i)
        std::cout << "--";

    std::cout << "\n";

    for (int row = 0; row < N; row++) {

        // Print queens on row
        for (int column = 0; column < N; column++) {

            if (candidateSolution.board[row] == column)
                std::cout << "|Q";
            else
                std::cout << "| ";
        }

        std::cout << "|\n";

        for (int column = 0; column < N; column++)
           std::cout << "--";

        std::cout << "\n";
    }
}

