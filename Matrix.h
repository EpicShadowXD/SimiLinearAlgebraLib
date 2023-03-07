#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <memory>
#include <cmath>

// SimiLinearAlgebraLibrary
namespace SimiLAL {

    template<typename T>
    class Matrix {
    public:
        Matrix() : Matrix(0)
        {}
        Matrix(size_t size) : Matrix(size, size)
        {}
        Matrix(size_t rowCount, size_t colCount) : rowCount(rowCount),
                                                colCount(colCount),
                                                data(rowCount, std::vector<T>(colCount))
        {}
        Matrix(const std::vector<std::vector<T>> &input) : data(input),
                                                           rowCount(input.size()),
                                                           colCount(input[0].size())
        {}

        // Linear Algebra
        void add(const Matrix& other);
        void sub(const Matrix& other);
        void mult(const Matrix& other);
        void div(const Matrix& other);

        void add(T value);
        void sub(T value);
        void mult(T value);
        void div(T value);

        bool isSquare();

        Matrix transpose();
        Matrix submatrix(size_t iPos, size_t jPos);

        double determinantLeibnitz();
        double determinantLU();

        // Iterators
        using RowIterator = std::vector<T>::iterator;
        using ColIterator = std::vector<std::reference_wrapper<T>>::iterator;

        RowIterator rowBegin(size_t index);
        RowIterator rowEnd(size_t index);

        ColIterator colBegin(size_t index);
        ColIterator colEnd(size_t index);

        // Utility
        std::vector<T>& operator[](size_t index);
        void insert(T element);
        void resize(size_t newRowCount, size_t newColCount);

        // Debug
        void print();

    private:
        size_t rowCount, colCount;
        std::vector<std::vector<T>> data;

        std::vector<std::reference_wrapper<T>> colVector;

        size_t currentInsertIPos = 0, currentInsertJPos = 0;

        // Helper
        void parseAllData(T value, T (*func)(const T&));
        void parseAllData(const Matrix& other, T (*func)(const T&, const T&));

        double determinantLeibnitzHelper(Matrix& self);
    };

}

