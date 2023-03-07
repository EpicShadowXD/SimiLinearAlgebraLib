#include <iostream>

#include "Matrix.cpp"

int main() {
    SimiLAL::Matrix<double> A({
                                      {5, 6,  7},
                                      {7, 8,  9},
                                      {9, 11, 11}
                              });

    SimiLAL::Matrix<double> B({
                                      {1, 2},
                                      {3, 4}
    });

    SimiLAL::Matrix<double> C({
                                      {2, 3},
                                      {4, 5}
    });

}