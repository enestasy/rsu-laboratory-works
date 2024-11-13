//20. Реализовать функцию преобразования числа типа int, заданного в системе счисления с основанием 10, в строковое представление числа в системе счисления с основанием из диапазона [2..36].

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 50

void convertToBase(int decimalNumber, int base, char* result) {
    const char digits[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"; // массив символов для цифр от 0 до 35
    int index = 0;
    int isNeg = 0;

    if (decimalNumber < 0) {
        isNeg = 1;
        decimalNumber = -decimalNumber;
    }

   if (decimalNumber == 0) {
        result[index++] = '0';
    }
   
   else {
        while (decimalNumber > 0) {
            int remainder = decimalNumber % base;
            result[index++] = digits[remainder];
            decimalNumber /= base;
        }
    }

    if (isNeg) {
        result[index++] = '-';
    }

    result[index] = '\0';

    // инвертирование строки
    for (int i = 0; i < index / 2; i++) {
        char temp = result[i];
        result[i] = result[index - i - 1];
        result[index - i - 1] = temp;
    }
}

int main() {
    int decimalNumber;
    int base;
    char result[MAX_LENGTH];

    printf("Enter a decimal number: ");
    scanf("%d", &decimalNumber);

    printf("Enter the base (2-36): ");
    scanf("%d", &base);

    // проверка, что основание в допустимом диапазоне
    if (base < 2 || base > 36) {
        printf("Error! Base must be between 2 and 36.\n");
        return -1;
    }

    convertToBase(decimalNumber, base, result);

    printf("Number in base %d: %s\n", base, result);

    return 0;
}
