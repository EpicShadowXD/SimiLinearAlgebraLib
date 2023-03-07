#include "Matrix.h"

#include "LinearAlgebra.cpp"
#include "Iterator.cpp"

namespace SimiLAL {
    // <Debug>
    template <typename T>
    void SimiLAL::Matrix<T>::print() {
        for (size_t i = 0; i < rowCount; i++) {
            for (size_t j = 0; j < colCount; j++)
                std::cout << data[i][j] << ' ';
            std::cout << std::endl;
        }
    }
    // </Debug>

    // <Utility>
    template <typename T>
    void SimiLAL::Matrix<T>::parseAllData(const Matrix<T> &other, T (*func)(const T &, const T &)) {
        for (size_t i = 0; i < rowCount; i++)
            for (size_t j = 0; j < colCount; j++)
                data[i][j] = func(data[i][j], other.data[i][j]);
    }

    template <typename T>
    void SimiLAL::Matrix<T>::insert(T element) {
        data[currentInsertIPos][currentInsertJPos] = element;

        currentInsertJPos++;

        // clamp
        if (currentInsertJPos >= colCount)
        {
            currentInsertJPos = 0;
            currentInsertIPos++;
        }
        if (currentInsertIPos >= rowCount)
            currentInsertIPos = 0;
    }
    template <typename T>
    std::vector<T>& SimiLAL::Matrix<T>::operator[](size_t index) { return data[index]; }

    template <typename T>
    void SimiLAL::Matrix<T>::resize(size_t newRowCount, size_t newColCount) {
        rowCount = newRowCount;
        colCount = newColCount;

        data.resize(rowCount, std::vector<T>(colCount));
    }

    // </Utility>
}
