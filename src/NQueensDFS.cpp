//
// Created by Tom Goring on 08/12/2018.
//

#include "NQueensDFS.h"
#include <vector>
#include <iostream>

candidateSolution workingCandidate;
std::vector<candidateSolution> openList;

int main(int argc, char **argv) {

    std::cout.flush();
    int startingColumnOfQueen = 0;

    addQueenToColumnOfWorkingCandidate(startingColumnOfQueen);

    printWorkingCandidate();
}




// Functions to manipulate a candidateSolution

void printCandidateSolution(candidateSolution candidateSolution) {

    // Print upper border of row
    for (int i = 0; i < N; ++i)
        std::cout << "--";

    std::cout << std::endl;;

    for (int row = 0; row < N; row++) {

        // Print queens on row
        for (int column = 0; column < N; column++) {

            if (candidateSolution.board[row] == column)
                std::cout << "|Q";
            else
                std::cout << "| ";
        }

        std::cout << "|" << std::endl;;

        for (int column = 0; column < N; column++)
           std::cout << "--";

        std::cout << std::endl;;
    }
}

bool hasValidBoard(candidateSolution candidateToTest) {

    return calculateNumberOfQueensUnderAttack(candidateToTest) <= 0;
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

// Functions to manipulate the workingCandidate

void addQueenToColumnOfWorkingCandidate(int columnToPlace) {

    int rowToPlace = workingCandidate.size;

    workingCandidate.board[rowToPlace] = columnToPlace;

    workingCandidate.size++;
}

void printWorkingCandidate() {

    printCandidateSolution(workingCandidate);
}

// Functions to manipulate list

void saveCandidateToOpenList(candidateSolution candidateToSave) {

    openList.push_back(candidateToSave);
}

void deleteLastEntryInOpenList() {

    openList.pop_back();
}

int getIndexOfCandidateSolution(candidateSolution candidateToFind) {

    int index = 0;
    bool found = false;

    while(!found) {

        if (openList[index].board == candidateToFind.board) {

            found = true;
        }

        index++;
    }

    return index;
}