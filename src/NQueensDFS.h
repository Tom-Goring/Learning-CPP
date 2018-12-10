//
// Created by tomgo on 08/12/2018.
//

#ifndef EXERCISES_NQUEENSDFS_H
#define EXERCISES_NQUEENSDFS_H

#endif //EXERCISES_NQUEENSDFS_H

#define N 8

struct candidateSolution {

    int board[N] = {-1, -1, -1, -1, -1, -1, -1, -1};
    int size = 0;
    bool valid = true;
};

void printCandidateSolution(candidateSolution candidateSolution);
bool hasValidBoard(candidateSolution candidatetoTest);
int calculateNumberOfQueensUnderAttack(candidateSolution candidateToTest);
void addQueenToColumnOfWorkingCandidate(int columnToPlace);
void printWorkingCandidate();
void saveCandidateToOpenList(candidateSolution candidateToSave);
void deleteLastEntryInOpenList();
int getIndexOfCandidateSolution(candidateSolution candidateToFind);