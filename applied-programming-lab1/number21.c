//21. Реализовать функцию преобразования строкового представления числа в системе счисления с основанием из диапазона [2..36] в число типа int, заданного в системе счисления с основанием 10.

#include <stdio.h>
#include <ctype.h>

#define MAX_LENGTH 50
// Функция для преобразования строки в число по схеме Горнера
int convertToDecimalHorner(const char* str, int base) {
    int result = 0;
    int sign = 1;    // знак числа (для отрицательных чисел)

    // проверка на знак числа
    if (*str == '-') {
        sign = -1;
        str++;
    } else if (*str == '+') {
        str++;
    }

    while (*str != '\0') {
        int value;

        if (isdigit(*str)) { //перевод в число
            value = *str - '0';
        }
        else if (isalpha(*str)) {
            value = toupper(*str) - 'A' + 10; 
        }
        else {
            // если символ недопустим
            printf("Invalid character: %c\n", *str);
            return -1;
        }
        
        // значение больше основания?
        if (value >= base) {
            printf("Invalid digit for base %d: '%c'\n", base, *str);
            return -1;
        }

        result = result * base + value;

        str++;
    }

    return sign * result;
}

int main() {
    char numberString[MAX_LENGTH];
    int base;

    printf("Enter a base of number: ");
    scanf(" %d", &base);
    
    printf("Enter a number string: ");
    scanf(" %s", numberString);

    int decimalNumber = convertToDecimalHorner(numberString, base);

    if (decimalNumber != -1) {
        printf("Decimal representation: %d\n", decimalNumber);
    }

    return 0;
}
