#ifndef N1_H
#define N1_H

#include <cstddef>

class Encoder {
    private:
        unsigned char *key;
        size_t key_size;
    public:
        Encoder(unsigned char const *new_key = nullptr, size_t new_key_size = 0);
        ~Encoder();

        void setKey(unsigned char const* new_key, size_t new_key_size);

        void initializeRC4(unsigned char S[256]) const;
        unsigned char generateByte(unsigned char S[256], int& i, int& j) const;

        void encode(char const* input_file, char const* output_file, bool encrypt) const;

        
};

#endif