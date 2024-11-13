//13.Имеется строка. Используя указатель типа char *, преобразовать каждый элемент, стоящий на нечётной позиции, в верхний регистр.

#include <stdio.h>
#include <ctype.h>

void oddUpper(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (i % 2 != 0) { // проверка на нечётность позиции
            str[i] = toupper(str[i]);
        }
    }
}

int main() {
    char str[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin); //stdin - это стандартный ввод

    // удаление символа переноса строки
    size_t len = 0;
    
    while (str[len] != '\0') {
        if (str[len] == '\n') {
            str[len] = '\0';
            break;
        }
        len++;
    }

    oddUpper(str);

    printf("Modified string: %s\n", str);

    return 0;
}
