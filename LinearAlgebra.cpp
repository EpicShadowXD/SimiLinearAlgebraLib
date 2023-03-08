#include "Matrix.h"

namespace SimiLAL {
    template <typename T>
    void Matrix<T>::add(const Matrix& other) {
        parseAllData(other, [](const T& left, const T& right){ return left + right; });
    }

    template <typename T>
    void Matrix<T>::sub(const Matrix& other) {
        parseAllData(other, [](const T& left, const T& right){ return left + right; });
    }

    template <typename T>
    void Matrix<T>::mult(const Matrix& other) {
        if (rowCount != other.colCount)
            throw std::invalid_argument("Matrix is not square");

        Matrix<T> temp(rowCount, other.colCount);

        for (size_t i = 0; i < temp.rowCount; i++)
            for (size_t j = 0; j < temp.colCount; j++)
                for (size_t k = 0; j < other.rowCount; k++)
                    temp.data[i][j] += (data[i][k] * other.data[k][j]);

        *this = temp;
    }


    template <typename T>
    bool Matrix<T>::isSquare() { return rowCount == colCount; }

    template <typename T>
    Matrix<T> Matrix<T>::transpose() {
        Matrix<T> temp(rowCount, colCount);

        for (int i = 0; i < rowCount; i++)
            for (int j = 0; j < colCount; j++)
                temp.data[j][i] = data[i][j];

        return temp;
    }

    template <typename T>
    Matrix<T> Matrix<T>::submatrix(size_t iPos, size_t jPos) {
        Matrix<T> temp(rowCount - 1);

        for (size_t i = 0; i < rowCount; i++)
        {
            if (i == iPos) continue;

            for (size_t j = 0; j < colCount; j++) {
                if (j == jPos) continue;

                temp.insert(data[i][j]);
            }
        }

        return temp;
    }

    template <typename T>
    double Matrix<T>::determinantLU() {
        if (!this->isSquare())
            throw std::invalid_argument("Matrix is not square");

        size_t n = rowCount;
        Matrix<T> LU = data;

        // Gaussian elimination
        size_t sign = 1;
        for (size_t k = 0; k < n - 1; k++) {
            for (size_t i = k + 1; i < n; i++) {
                T factor = LU.data[i][k] / LU.data[k][k];

                for (size_t j = k + 1; j < n; j++)
                    LU.data[i][j] -= factor * LU.data[k][j];

                LU.data[i][k] = factor;
            }
        }

        // Compute determinant
        T det = sign;
        for (size_t i = 0; i < n; i++)
            det *= LU.data[i][i];

        return det;
    }


    template <typename T>
    double Matrix<T>::determinantLeibnitz() { return determinantLeibnitzHelper(*this); }

    template <typename T>
    double Matrix<T>::determinantLeibnitzHelper(Matrix& self) {
        if (!this->isSquare())
            throw std::invalid_argument("Matrix is not square");

        if (self.rowCount == 2)
            return (self.data[0][0] * self.data[1][1]) - (self.data[0][1] * self.data[1][0]);

        double determinant = 0;
        for (size_t jUpperRow = 0; jUpperRow < colCount; jUpperRow++) {
            Matrix<T> subMatrix = self.submatrix(0, jUpperRow);

            determinant += self[0][jUpperRow] * pow(-1, jUpperRow) * subMatrix.determinantLeibnitzHelper(subMatrix);
        }

        return determinant;
    }
}