//
// Created by tomgo on 08/12/2018.
//

#ifndef EXERCISES_NQUEENSDFS_H
#define EXERCISES_NQUEENSDFS_H

#endif //EXERCISES_NQUEENSDFS_H

#define N 8

struct candidateSolution {

    int board[N] = {0, 1, 2, 3, 4, 5, 6, 7};
    int size = 8;
    bool valid = true;
};

int calculateNumberOfQueensUnderAttack(candidateSolution candidateToTest);
void printCandidateSolution(candidateSolution candidateSolution);
