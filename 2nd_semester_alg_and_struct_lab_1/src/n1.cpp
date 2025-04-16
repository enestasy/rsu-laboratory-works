#include "n1.hpp"

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <algorithm>

Encoder::Encoder(unsigned char const *new_key, size_t new_key_size)
    : key_size(new_key_size) {
    if (new_key_size > 0) {
        key = new unsigned char[key_size];
        std::copy(new_key, new_key + key_size, key);
    } else {
        key = nullptr;
    }
}

Encoder::~Encoder() {
    delete[] key;
}

void Encoder::setKey(unsigned char const* new_key, size_t new_key_size) {
    delete[] key;
    key = nullptr;
    if (new_key_size > 0) {
        key = new unsigned char[new_key_size];
        key_size = new_key_size;
        std::copy(new_key, new_key + new_key_size, key); 
    }
    
}


void Encoder::initializeRC4(unsigned char S[256]) const {
    for (int i = 0; i < 256; ++i) {
        S[i] = i;
    }

    int j = 0;
    for (int i = 0; i < 256; ++i) {
        j = (j + S[i] + key[i % key_size]) % 256;
        std::swap(S[i], S[j]);
    }
}

unsigned char Encoder::generateByte(unsigned char S[256], int& i, int& j) const {
    i = (i + 1) % 256;
    j = (j + S[i]) % 256;
    std::swap(S[i], S[j]);
    return S[(S[i] + S[j]) % 256];
}

void Encoder::encode(char const* input_file, char const* output_file, bool encrypt) const {
    std::ifstream input(input_file, std::ios::binary);
    if (!input) {
        throw std::runtime_error("Failed to open input file");
    }

    std::ofstream output(output_file, std::ios::binary);
    if (!output) {
        throw std::runtime_error("Failed to open output file");
    }

    if (encrypt) {
        std::cout << "Encrypting file..." << std::endl;
    } else {
        std::cout << "Decrypting file..." << std::endl;
    }

    unsigned char S[256];

    std::cout << "Initializing RC4..." << std::endl;
    initializeRC4(S);

    int i = 0, j = 0;

    unsigned char byte;
    size_t processed_bytes = 0;

    std::cout << "Processing file..." << std::endl;
    while (input.read(reinterpret_cast<char *>(&byte), sizeof(byte))) {
        unsigned char keystream_byte = generateByte(S, i, j);
        byte ^= keystream_byte;
        output.write(reinterpret_cast<char *>(&byte), sizeof(byte));
        processed_bytes++;
    }

    std::cout << "Processed " << processed_bytes << " bytes." << std::endl;

    input.close();
    output.close();

}
