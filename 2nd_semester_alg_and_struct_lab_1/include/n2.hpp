#ifndef N2_HPP
#define N2_HPP

#include <cstddef>

class logical_values_array {
    private:
        unsigned int _value;
    public:
        logical_values_array(unsigned int value = 0);

        unsigned int get_value() const;

        logical_values_array operator~() const;
        logical_values_array operator|(const logical_values_array& other) const;
        logical_values_array operator&(const logical_values_array& other) const;
        logical_values_array operator^(const logical_values_array& other) const;

        bool operator[](size_t position) const;

        logical_values_array implication(const logical_values_array& other) const;
        logical_values_array coimplication(const logical_values_array& other) const;
        logical_values_array equivalence(const logical_values_array& other) const;
        logical_values_array Pierce_arrow(const logical_values_array& other) const;
        logical_values_array Sheffer_stroke(const logical_values_array& other) const;

        static bool equals(const logical_values_array& lhs, const logical_values_array& rhs);
        bool get_bit(size_t position) const;

        void to_binary_string(char* buffer) const;

};

#endif