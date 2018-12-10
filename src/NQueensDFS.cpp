//
// Created by Tom Goring on 08/12/2018.
//
// DO NOT USE THIS FOR ANY COURSEWORK YOU HAVE - It'll probably get caught in a closeness test and banned - it's not worth
// getting kicked out for.
//
// Any feedback on how to improve this / make it more "c++ like" is appreciated.
//

#include "NQueensDFS.h"
#include <vector>
#include <iostream>
#include <cstring>


candidateSolution workingCandidate;
std::vector<candidateSolution> openList; // a list of solutions we have yet to examine


int main(int argc, char **argv) {

    bool solutionFound = false;
    int numberOfSolutionsExamined = 0;

    //set up the board with a starting queen

    std::cout.flush();

    int startingColumnOfQueen = 0;

    addQueenToColumnOfNextRowInWorkingCandidate(startingColumnOfQueen);
    saveWorkingCandidateToOpenList();
    testCurrentWorkingCandidate();

    // start the depth-first search to find the solution

    while (!solutionFound && !openList.empty()) {

        if (workingCandidate.valid) {

            deleteLastEntryInOpenList();
            generateChildrenOfWorkingCandidate();

            setWorkingCandidateToLastCandidateInOpenList();
        }
        else {

            deleteLastEntryInOpenList();
            setWorkingCandidateToLastCandidateInOpenList();
        }

        //printWorkingCandidate();
        testCurrentWorkingCandidate();
        numberOfSolutionsExamined++;


        if (workingCandidate.size == N && hasValidBoard(workingCandidate)) {

            solutionFound = true;
        }
    }

    std::cout.flush();
    std::cout << "Solution found in " << numberOfSolutionsExamined << " moves: " << std::endl;
    printWorkingCandidate();
    std::cin.get();

}

void printCandidateSolution(candidateSolution candidateSolution) {

    // Print upper border of row
    for (int i = 0; i < N; ++i)
        std::cout << "--";

    std::cout << std::endl;;

    for (int row : candidateSolution.board) {

        // Print queens on row
        for (int column = 0; column < N; column++) {

            if (row == column)
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

    // for every queen
    for (int qToExamine = 0; qToExamine < candidateToTest.size; ++qToExamine) {

        // check all rows that haven't already been checked - to prevent from making previously made comparisons.
        for (int qToCompare = qToExamine + 1; qToCompare < candidateToTest.size; ++qToCompare) {

            // test to see if queens are in same column
            if (candidateToTest.board[qToExamine] == candidateToTest.board[qToCompare]) {

                vulnerableQueens++;
            }

            int deltaRow;
            int deltaCol;
            int difference;

            deltaRow = qToExamine - qToCompare;
            deltaCol = workingCandidate.board[qToExamine] - workingCandidate.board[qToCompare];

            difference = deltaRow - deltaCol;

            if (difference == 0) {

                vulnerableQueens++;
            }

            difference = deltaRow + abs(deltaCol);

            if (difference == 0) {

                vulnerableQueens++;
            }
        }
    }

    return vulnerableQueens;
}

int testCurrentWorkingCandidate() {

    // if working candidate has more than 0 queens under attack, it is neither a valid partial or full solution
    workingCandidate.valid = calculateNumberOfQueensUnderAttack(workingCandidate) <= 0;
}

void addQueenToColumnOfNextRowInWorkingCandidate(int columnToPlace) {

    int rowToPlace = workingCandidate.size;

    workingCandidate.board[rowToPlace] = columnToPlace;

    workingCandidate.size++;
}

void moveQueenInRowToColumnOfWorkingCandidate(int rowToMoveIn, int columnToMoveTo) {

    workingCandidate.board[rowToMoveIn] = columnToMoveTo;
}

void generateChildrenOfWorkingCandidate() {

    int currentRow = workingCandidate.size;

    addQueenToColumnOfNextRowInWorkingCandidate(0);

    for (int column = 0; column < N; ++column) {

        moveQueenInRowToColumnOfWorkingCandidate(currentRow, column);
        saveWorkingCandidateToOpenList();
    }
}

void printWorkingCandidate() {

    printCandidateSolution(workingCandidate);
}

void saveWorkingCandidateToOpenList() {

    openList.push_back(workingCandidate);
}

void deleteLastEntryInOpenList() {

    openList.pop_back();
}

void setWorkingCandidateToLastCandidateInOpenList() {

    workingCandidate = openList.back();
}