#include <iostream>

#include "Matrix.cpp"

int main() {
    SimiLAL::Matrix<double> B({
                                      {5, 6,  7},
                                      {7, 8,  9},
                                      {9, 11, 11}
                              });

    SimiLAL::Matrix<double> Bt = B.transpose();
    Bt.print();
}