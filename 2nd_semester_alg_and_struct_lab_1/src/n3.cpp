#include "n3.hpp"

#include <iostream>
#include <cmath>

Complex::Complex(double c_real, double c_imaginary)
    :  real(c_real), imaginary(c_imaginary) {}

Complex Complex::operator+(const Complex& other) const {
    double new_real = getReal() + other.getReal();
    double new_imaginary = getImaginary() + other.getImaginary();
    return Complex(new_real, new_imaginary);
}

Complex Complex::operator-(const Complex& other) const {
    double new_real = getReal() - other.getReal();
    double new_imaginary = getImaginary() - other.getImaginary();
    return Complex(new_real, new_imaginary);
}

Complex Complex::operator*(const Complex& other) const {
    double new_real = getReal() * other.getReal() - getImaginary() * other.getImaginary();
    double new_imaginary = getReal() * other.getImaginary() + other.getReal() * getImaginary();
    return Complex(new_real, new_imaginary);
}

Complex Complex::operator/(const Complex& other) const {
    double denominator = other.getReal() * other.getReal() + other.getImaginary() * other.getImaginary();

    if (denominator == 0.0) {
        throw std::runtime_error("Division by zero in Complex division");
    }

    double new_real = (getReal() * other.getReal() + getImaginary() * other.getImaginary())/denominator;
    double new_imaginary = (getImaginary() * other.getReal() - getReal() * other.getImaginary())/denominator;

    return Complex(new_real, new_imaginary);
}

Complex& Complex::operator+=(const Complex& other) {
    real += other.getReal();
    imaginary += other.getImaginary();
    return *this;
}

Complex& Complex::operator-=(const Complex& other) {
    real -= other.getReal();
    imaginary -= other.getImaginary();
    return *this;
}

Complex& Complex::operator*=(const Complex& other) {
    *this = *this * other;
    return *this;
}

Complex& Complex::operator/=(const Complex& other) {
    *this = *this / other;
    return *this;

}

double Complex::getModulus() const {
    double mod = std::sqrt(getReal() * getReal() + getImaginary() * getImaginary());
    return mod;
}

double Complex::getArgument() const {
    double arg = std::atan2(getImaginary(), getReal());
    return arg;
}

std::ostream& operator<<(std::ostream& os, const Complex& c) {
    return os << c.getReal() << "+" << c.getImaginary() << "i";
}

std::istream& operator>>(std::istream& is, Complex& c) {
    double r, i;
    is >> r >> i;
    c.setReal(r);
    c.setImaginary(i);
    return is;
}