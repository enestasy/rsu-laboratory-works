#include "n4.hpp"

#include <iostream>
#include <stdexcept>

Matrix::Matrix(size_t r, size_t c) : rows(r), cols(c) {
    data = new double*[rows];

    for (size_t i = 0; i < rows; ++i) {
        data[i] = new double[cols];
        for (size_t j = 0; j < cols; ++j) {
            data[i][j] = 0.0;
        }
    } 
}

Matrix::~Matrix() {
    for (size_t i = 0; i < rows; ++i) {
        delete[] data[i];
    }
    delete[] data;
}

Matrix Matrix::operator+(const Matrix& other) const {
    if ((getCols() != other.getCols()) || (getRows() != other.getRows())) {
        throw std::length_error("Couldn`t summarize. The number of columns and rows are different");
    }

    Matrix new_matrix(getRows(), getCols());

    for (size_t i = 0; i < getRows(); ++i) {
        for (size_t j = 0; j < getCols(); ++j) {
            new_matrix.data[i][j] = data[i][j] + other.data[i][j];
        }
    }
    return new_matrix;
}

Matrix Matrix::operator-(const Matrix& other) const {
    if ((getCols() != other.getCols()) || (getRows() != other.getRows())) {
        throw std::length_error("Couldn`t subtract. The number of columns and rows are different");
    }

    Matrix new_matrix(getRows(), getCols());

    for (size_t i = 0; i < getRows(); ++i) {
        for (size_t j = 0; j < getCols(); ++j) {
            new_matrix.data[i][j] = data[i][j] - other.data[i][j];
        }
    }
    return new_matrix;
}

Matrix Matrix::operator*(const Matrix& other) const {
    if (getCols() != other.getRows()) {
        throw std::length_error("The number of columns of the first matrix is not equal to the number of rows of the second");
    }

    Matrix new_matrix(getRows(), other.getCols());

    for (size_t i = 0; i < getRows(); ++i) {
        for (size_t j = 0; j < getCols(); ++j) {
            for (size_t k = 0; k < getCols(); ++k) {
                //TODO: do smth to summarize compositions
            }
        }
    }

}

Matrix Matrix::operator*(double scalar) const {
    Matrix new_matrix(getRows(), getCols());

    for (size_t i = 0; i < getRows(); ++i) {
        for (size_t j = 0; j < getCols(); ++j) {
            new_matrix.data[i][j] = data[i][j] * scalar;
        }
    }
    return new_matrix;
}

double *Matrix::operator[](size_t row) {
    //TODO: check indexes
    return data[row];
}

const double *Matrix::operator[](size_t row) const {
    //TODO: check indexes
    return data[row];
}

Matrix Matrix::transposition() const {
    Matrix new_matrix(getRows(), getCols());

    for (size_t i = 0; i < getRows(); ++i) {
        for (size_t j = 0; j < getCols(); ++j) {
            new_matrix.data[i][j] = data[j][i];
        }
    }
    return new_matrix;
}

double Matrix::findDeterminant() const {
    return 0.0;
}

Matrix Matrix::findInverse() const {
    return Matrix();
}

std::ostream& operator<<(std::ostream &os, const Matrix &matrix) {
    for (size_t i = 0; i < matrix.rows; ++i) {
        for (size_t j = 0; j < matrix.cols; ++j) {
            os << matrix[i][j] << " ";
        }
        os << std::endl;
    }
    return os;
}