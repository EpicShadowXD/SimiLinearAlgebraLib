#include <iostream>

#include "Matrix.cpp"

int main() {
    SimiLAL::Matrix<double> A({
                                      {1, 2},
                                      {3, 4}
    });

    SimiLAL::Matrix<double> B({
                                      {2, 3},
                                      {4, 5}
    });

    A.mult(B);
    A.print();
}