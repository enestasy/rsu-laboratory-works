#ifndef N3_HPP
#define N3_HPP

#include <ostream>
#include <istream>

class Complex
{
private:
    double real, imaginary;

public:
    Complex(double c_real = 0.0, double c_imaginary = 0.0);

    Complex operator+(const Complex& other) const;
    Complex operator-(const Complex& other) const;
    Complex operator*(const Complex& other) const;
    Complex operator/(const Complex& other) const;

    Complex& operator+=(const Complex& other);
    Complex& operator-=(const Complex& other);
    Complex& operator*=(const Complex& other);
    Complex& operator/=(const Complex& other);

    double getReal() const { return real; }
    double getImaginary() const { return imaginary; }

    void setReal(double value) {real = value; }
    void setImaginary(double value) {imaginary = value; }

    double getModulus() const;
    double getArgument() const;

    friend std::ostream& operator<<(std::ostream& os, const Complex& c);
    friend std::istream& operator>>(std::istream& is, Complex& c);
};

#endif
