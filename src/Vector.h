//
// Created by Tom Goring on 07/12/2018.
//

#ifndef EXERCISES_VECTOR_H
#define EXERCISES_VECTOR_H
#endif //EXERCISES_VECTOR_H

class Vector {

public:
    explicit Vector(int s);
    double& operator[](int i);
    int size();

private:
    double *elem;
    int sz;
};

void TestVRangeException(Vector& v);
