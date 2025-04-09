#include "n2.hpp"

#include <cstddef>
#include <stdexcept>

logical_values_array::logical_values_array(unsigned int value) 
    : _value(value) {};

unsigned int logical_values_array::get_value() const
{
    return _value;
}

logical_values_array logical_values_array::operator~() const {
    return logical_values_array(~_value);
}

logical_values_array logical_values_array::operator|(const logical_values_array &other) const {
    return logical_values_array(_value | other._value);
}

logical_values_array logical_values_array::operator&(const logical_values_array& other) const {
    return logical_values_array(_value & other._value);
}

logical_values_array logical_values_array::operator^(const logical_values_array &other) const {
    return logical_values_array(_value ^ other._value);
}

bool logical_values_array::equals(const logical_values_array& lhs, const logical_values_array& rhs) {
    return lhs._value == rhs._value;
}


bool logical_values_array::get_bit(size_t position) const
{
    if (position >= sizeof(unsigned int) * 8) {
        throw std::out_of_range("Bit position out of range");
    }
    return (_value >> position) & 1;
}

bool logical_values_array::operator[](size_t position) const {
    return get_bit(position);
}

logical_values_array logical_values_array::implication(const logical_values_array& other) const {
    return ~(*this) | other;
}

logical_values_array logical_values_array::coimplication(const logical_values_array& other) const {
    return *this | ~other;
}

logical_values_array logical_values_array::equivalence(const logical_values_array& other) const {
    return (*this | ~other) & (~(*this) | other);
}

logical_values_array logical_values_array::Pierce_arrow(const logical_values_array& other) const {
    return ~(*this | other);
}

logical_values_array logical_values_array::Sheffer_stroke(const logical_values_array& other) const {
    return ~(*this & other);
}

void logical_values_array::to_binary_string(char* buffer) const {
    for (size_t i = 0; i < sizeof(unsigned int) * 8; ++i) {
        buffer[sizeof(unsigned int) * 8 - 1 - i] = ((_value >> i) & 1) ? '1' : '0';
    }
    buffer[sizeof(unsigned int) * 8] = '\0';
}