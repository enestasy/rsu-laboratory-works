#include <iostream>
#include <stdexcept>

#include "include/n1.hpp"
#include "include/n3.hpp"


int main() {
    try {

        std::cout << "TASK 1\n\n" << std::endl;

        unsigned char key[] = {0x01, 0x02, 0x03, 0x04, 0x05};
        size_t key_size = sizeof(key) / sizeof(key[0]);

        Encoder encoder(key, key_size);

        encoder.encode("/home/enestasy/Documents/RSU named after Kosygin/Programming and algorithms/Лабораторная Ирбитский/2nd_semester_alg_and_struct_lab_1/data/input.txt", "/home/enestasy/Documents/RSU named after Kosygin/Programming and algorithms/Лабораторная Ирбитский/2nd_semester_alg_and_struct_lab_1/data/encrypted.txt", true);

        encoder.encode("/home/enestasy/Documents/RSU named after Kosygin/Programming and algorithms/Лабораторная Ирбитский/2nd_semester_alg_and_struct_lab_1/data/encrypted.txt", "/home/enestasy/Documents/RSU named after Kosygin/Programming and algorithms/Лабораторная Ирбитский/2nd_semester_alg_and_struct_lab_1/data/decrypted.txt", true);

        std::cout << "Encryption and decryption completed successfully!" << std::endl;


        std::cout << "TASK 3\n\n" << std::endl;

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