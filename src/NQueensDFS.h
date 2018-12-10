//
// Created by tomgo on 08/12/2018.
//

#ifndef EXERCISES_NQUEENSDFS_H
#define EXERCISES_NQUEENSDFS_H
#endif //EXERCISES_NQUEENSDFS_H

#define N 8 // number of queens / size of board

// perhaps setting the [] operator to accessing board would be better? unsure.
struct candidateSolution {

    // reference the board as - board[row] = column - to put a row in that rows column.
    int board[N] = {0};

    int size = 0;
    bool valid = true;
};

void printCandidateSolution(candidateSolution candidateSolution);
bool hasValidBoard(candidateSolution candidateToTest);
int calculateNumberOfQueensUnderAttack(candidateSolution candidateToTest);
int testCurrentWorkingCandidate();
void addQueenToColumnOfNextRowInWorkingCandidate(int columnToPlace);
void moveQueenInRowToColumnOfWorkingCandidate(int rowToMoveIn, int columnToMoveTo);
void generateChildrenOfWorkingCandidate();
void printWorkingCandidate();
void saveWorkingCandidateToOpenList();
void deleteLastEntryInOpenList();
void setWorkingCandidateToLastCandidateInOpenList();