#ifndef N4_HPP
#define N4_HPP

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
        //TODO: Copying constructor, the assignment operator
        ~Matrix();
        

        Matrix operator+(const Matrix& other) const;
        Matrix operator*(const Matrix& other) const;
        Matrix operator-(const Matrix& other) const;

        Matrix operator*(double scalar) const;

        double* operator[](size_t row);
        const double* operator[](size_t row) const;

        friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix);
        friend std::istream& operator>>(std::istream& is, Matrix& matrix);

        Matrix transposition() const;
        double findDeterminant() const;
        Matrix findInverse() const;

        size_t getRows() const {return rows;}
        size_t getCols() const {return cols;}


};


#endif