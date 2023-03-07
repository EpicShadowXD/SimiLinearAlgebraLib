#include <iostream>

#include "Matrix.cpp"

int main() {
    SimiLAL::Matrix<double> A({
                                      {5, 6,  7},
                                      {7, 8,  9},
                                      {9, 11, 11}
                              });

    std::cout << A.determinantLU();
}