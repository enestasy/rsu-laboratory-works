#ifndef N4_H
#define N4_H

#include <cstddef>

class Matrix {
    private:
        double** data;
        size_t rows;
        size_t cols;

    public:
        Matrix(size_t rows, size_t cols);
        ~Matrix();
        

        Matrix operator+(const Matrix& other) const;
        Matrix operator*(const Matrix& other) const;
        Matrix operator*(const double& other) const;
        Matrix operator-(const Matrix& other) const;

        Matrix transposition() const;
        double findDeterminant() const;
        Matrix findInverse() const;


};


#endif