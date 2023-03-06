#include "Matrix.h"

namespace SimiLAL {
    template <typename T>
    SimiLAL::Matrix<T>::RowIterator Matrix<T>::rowBegin(size_t index) { return data[index].begin(); }

    template <typename T>
    SimiLAL::Matrix<T>::RowIterator Matrix<T>::rowEnd(size_t index) { return data[index].end(); }

    template <typename T>
    SimiLAL::Matrix<T>::ColIterator Matrix<T>::colBegin(size_t index) {
        colVector.erase(colVector.begin(), colVector.end());

        for (size_t i = 0; i < rowCount; i++)
            colVector.push_back(std::ref(data[i][index]));

        return colVector.begin();
    }

    template <typename T>
    SimiLAL::Matrix<T>::ColIterator Matrix<T>::colEnd(size_t index) { return colVector.end(); }
}