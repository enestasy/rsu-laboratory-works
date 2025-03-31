#include <iostream>
#include <stdexcept>


#include "include/n3.hpp"


int main() {
    try {

        std::cout << "TASK 3\n\n";
        Complex c1(5.6, 3.7);
        Complex c2(2.9, 10.8);

        std::cout << "Initial values:" << std::endl;
        std::cout << "c1 = " << c1 << std::endl;
        std::cout << "c2 = " << c2 << std::endl;

        std::cout << "\nTesting operators:" << std::endl;
        std::cout << "c1 + c2 = " << (c1 + c2) << std::endl;
        std::cout << "c1 - c2 = " << (c1 - c2) << std::endl;
        std::cout << "c1 * c2 = " << (c1 * c2) << std::endl;
        std::cout << "c1 / c2 = " << (c1 / c2) << std::endl;

        std::cout << "\nTesting modulus and argument:" << std::endl;
        std::cout << "Modulus of c1: " << c1.getModulus() << std::endl;
        std::cout << "Argument of c1: " << c1.getArgument() << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}