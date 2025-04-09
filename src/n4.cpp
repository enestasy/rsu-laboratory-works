#include "n4.hpp"

#include <iostream>

Matrix(size_t r, size_t c) : rows(r), cols(c) {
    data = new double*[rows];

    for (size_t i = 0; i < rows; ++i) {
        data[i] = new double[cols];
        for (size_t j = 0; j < cols; ++j) {
            data[i][j] = 0.0;
        }
    } 
};