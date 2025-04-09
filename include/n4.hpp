#ifndef N4_H
#define N4_H

#include <cstddef>
#include <ostream>
#include <istream>

class Matrix {
    private:
        double** data;
        size_t rows;
        size_t cols;

    public:
        Matrix(size_t rows = 0, size_t cols = 0);
        ~Matrix();
        

        Matrix operator+(const Matrix& other) const;
        Matrix operator*(const Matrix& other) const;
        Matrix operator*(const double& other) const;
        Matrix operator-(const Matrix& other) const;

        Matrix& operator[](size_t row, size_t col) const;

        ostream operator<<() const;


        Matrix transposition() const;
        double findDeterminant() const;
        Matrix findInverse() const;


};


#endif