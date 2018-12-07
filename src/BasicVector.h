//
// Created by Tom Goring on 07/12/2018.
//

#ifndef EXERCISES_VECTOR_H
#define EXERCISES_VECTOR_H
#endif //EXERCISES_VECTOR_H

class BasicVector {

public:
    explicit BasicVector(int s);
    ~BasicVector();
    double& operator[](int i);
    int size();

private:
    double *elem;
    int sz;
};

void TestVRangeException(BasicVector& v);
void TestVectorConstructor();