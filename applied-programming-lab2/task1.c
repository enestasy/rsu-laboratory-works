/* Задание 1. Реализовать функцию перевода числа из десятичной системы счисления в систему счисления с
основанием 2^r , r = 1, …, 5. При реализации функции разрешается использовать битовые
операции и операции обращения к памяти, запрещается использовать стандартные
арифметические операции. Продемонстрируйте работу реализованной функции.

*/

#include <stdio.h>
#include <stdlib.h>

#define MEMORY_ALLOCATION_ERROR 2
#define INVALID_INPUT_ERROR 3


int decimal_to_base2r(unsigned int number, unsigned int r, unsigned int **result, unsigned int *length) {
    if (r < 1 || r > 5) {
        return INVALID_INPUT_ERROR;
    }

    unsigned int base = 1 << r;
    unsigned int mask = base - 1;

    *length = 0;
    unsigned int temp = number;
    while (temp > 0) {
        (*length)++;
        temp >>= r;
    }

    *result = malloc(*length * sizeof(unsigned int));
    if (*result == NULL) {
        return MEMORY_ALLOCATION_ERROR;
    }

    for (unsigned int i = 0; i < *length; i++) {
        (*result)[i] = number & mask;
        number >>= r;
    }

    return 0;
}


int main() {
    unsigned int number = 876567;
    unsigned int r = 1;

    unsigned int *result = NULL;
    unsigned int length = 0;

    int status = decimal_to_base2r(number, r, &result, &length);
    if (status != 0) {
        return status;
    }

    printf("Number %u in base 2^%u: ", number, r);
    for (int i = length - 1; i >= 0; i--) {
        printf("%u", result[i]);
    }
    printf("\n");

    free(result);

    return 0;
}
