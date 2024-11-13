//11.Реализовать функцию подсчета длины строки, аналогичную стандартной функции strlen
#include <stdio.h>

size_t ownStrlen(const char *str) { //size_t — беззнаковый целый тип, предназначенный для представления размера любого объекта в памяти (включая массивы) в конкретной реализации.

    size_t length = 0;

    // проходим по строке до тех пор, пока не встретится нулевой символ
    while (*str != '\0') {
        length++; // длина +1
        str++;    // переход к следующему символу
    }

    return length;
}

int main() {
    char str[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin); // считываем строку

    // удаление символа переноса на новую строку
    size_t len = ownStrlen(str);
    if (str[len - 1] == '\n') {
        str[len - 1] = '\0';
        len--;
    }

    printf("The length of the string is: %zu\n", len); // %zu — формат для size_t

    return 0;
}
