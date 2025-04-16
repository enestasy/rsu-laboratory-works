#include <iostream>
#include <stdexcept>

#include "include/n1.hpp"
#include "include/n2.hpp"
#include "include/n3.hpp"
#include "include/n4.hpp"


int main() {
    try {

        std::cout << "TASK 1\n\n" << std::endl;

        unsigned char key[] = {0x01, 0x02, 0x03, 0x04, 0x05};
        size_t key_size = sizeof(key) / sizeof(key[0]);

        Encoder encoder(key, key_size);

        encoder.encode("data/input.txt", "data/encrypted.txt", true);

        encoder.encode("data/encrypted.txt", "data/decrypted.txt", true);

        unsigned char new_key[] = {0x2A, 0x7F, 0xC4, 0x19, 0xE3};
        size_t new_key_size = sizeof(new_key) / sizeof(new_key[0]);

        encoder.setKey(new_key, new_key_size);

        encoder.encode("data/input.txt", "data/encrypted.txt", true);

        encoder.encode("data/encrypted.txt", "data/decrypted.txt", true);

        std::cout << "Encryption and decryption completed successfully!" << std::endl;

        std::cout << "\nTASK 2\n\n" << std::endl;

        logical_values_array a(0b1010101110011010101010);
        logical_values_array b(0b11001110101001000101000);

        std::cout << "Initial values:" << std::endl;
        std::cout << "a = " << a.get_value() << " (binary: ";
        char buffer[33];
        a.to_binary_string(buffer);
        std::cout << buffer << ")" << std::endl;

        std::cout << "b = " << b.get_value() << " (binary: ";
        b.to_binary_string(buffer);
        std::cout << buffer << ")" << std::endl;

        std::cout << "\nLogical operations:" << std::endl;

        logical_values_array not_a = ~a;
        std::cout << "~a = " << not_a.get_value() << " (binary: ";
        not_a.to_binary_string(buffer);
        std::cout << buffer << ")" << std::endl;

        logical_values_array and_result = a & b;
        std::cout << "a & b = " << and_result.get_value() << " (binary: ";
        and_result.to_binary_string(buffer);
        std::cout << buffer << ")" << std::endl;

        logical_values_array or_result = a | b;
        std::cout << "a | b = " << or_result.get_value() << " (binary: ";
        or_result.to_binary_string(buffer);
        std::cout << buffer << ")" << std::endl;

        logical_values_array xor_result = a ^ b;
        std::cout << "a ^ b = " << xor_result.get_value() << " (binary: ";
        xor_result.to_binary_string(buffer);
        std::cout << buffer << ")" << std::endl;

        logical_values_array implication_result = a.implication(b);
        std::cout << "a -> b = " << implication_result.get_value() << " (binary: ";
        implication_result.to_binary_string(buffer);
        std::cout << buffer << ")" << std::endl;

        logical_values_array coimplication_result = a.coimplication(b);
        std::cout << "a <- b = " << coimplication_result.get_value() << " (binary: ";
        coimplication_result.to_binary_string(buffer);
        std::cout << buffer << ")" << std::endl;

        logical_values_array equivalence_result = a.equivalence(b);
        std::cout << "a <-> b = " << equivalence_result.get_value() << " (binary: ";
        equivalence_result.to_binary_string(buffer);
        std::cout << buffer << ")" << std::endl;

        logical_values_array pierce_arrow_result = a.Pierce_arrow(b);
        std::cout << "a ↓ b = " << pierce_arrow_result.get_value() << " (binary: ";
        pierce_arrow_result.to_binary_string(buffer);
        std::cout << buffer << ")" << std::endl;

        logical_values_array sheffer_stroke_result = a.Sheffer_stroke(b);
        std::cout << "a | b (Sheffer stroke) = " << sheffer_stroke_result.get_value() << " (binary: ";
        sheffer_stroke_result.to_binary_string(buffer);
        std::cout << buffer << ")" << std::endl;

        std::cout << "\nBit access methods:" << std::endl;
        std::cout << "a.get_bit(2) = " << a.get_bit(2) << std::endl;
        std::cout << "a[2] = " << a[2] << std::endl;

        std::cout << "\nBinary string representation:" << std::endl;
        a.to_binary_string(buffer);
        std::cout << "a as binary string: " << buffer << std::endl;

        std::cout << "\nComparison of objects:" << std::endl;
        std::cout << "a equals b? " << logical_values_array::equals(a, b) << std::endl;
        std::cout << "a equals a? " << logical_values_array::equals(a, a) << std::endl;


        std::cout << "\nTASK 3\n\n" << std::endl;

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

        std::cout << "\nTASK 4\n\n" << std::endl;

        Matrix m1(3, 3), m2(3, 3);

        m1[0][0] = 1.0;
        m1[0][1] = 2.0;
        m1[0][2] = 3.0;
        m1[1][0] = 4.0;
        m1[1][1] = 5.0;
        m1[1][2] = 6.0;
        m1[2][0] = 7.0;
        m1[2][1] = 8.0;
        m1[2][2] = 9.0;

        m2[0][0] = 1.5;
        m2[0][1] = 2.6;
        m2[0][2] = 3.7;
        m2[1][0] = 4.8;
        m2[1][1] = 5.9;
        m2[1][2] = 6.1;
        m2[2][0] = 7.2;
        m2[2][1] = 8.3;
        m2[2][2] = 9.4;

        std::cout << "Matrix A:" << std::endl;
        std::cout << m1 << std::endl;

        std::cout << "Matrix A determinant:" << std::endl;
        std::cout << m1.findDeterminant() << std::endl;

        std::cout << "Matrix A inverse:" << std::endl;
        std::cout << m1.findInverse() << std::endl;

        std::cout << "Transposed matrix A:" << std::endl;
        std::cout << m1.transposition() << std::endl;

        std::cout << "Matrix A * 5:" << std::endl;
        std::cout << m1 * 5 << std::endl;

        std::cout << "Matrix B:" << std::endl;
        std::cout << m2 << std::endl;

        std::cout << "Matrix A + B:" << std::endl;
        std::cout << m1 + m2 << std::endl;

        std::cout << "Matrix A - B:" << std::endl;
        std::cout << m1 - m2 << std::endl;

        


    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}