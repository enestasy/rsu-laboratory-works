#include <stdio.h>

char *ownStrstr(const char *motherStr, const char *daughterStr) {
    // если подстрока пустая, возвращается исходная строка
    if (*daughterStr == '\0') {
        return (char *)motherStr;
    }

    // поиск подстроки
    while (*motherStr) {
        const char *m = motherStr;
        const char *d = daughterStr;

        while (*m && *d && (*m == *d)) {// сравнение подстроки и части строки
            m++;
            d++;
        }

        if (*d == '\0') {// если достигли конца подстроки, возвращаем указатель на её начало
            return (char *)motherStr;
        }

        motherStr++;
    }

    // если подстрока не найдена, возвращаем NULL
    
    return NULL;
}

int main() {
    char str[100];
    char sub[50];
    char *result;

    printf("Enter the main string: ");
    scanf(" %[^\n]", str); //"%[^\n]" - считывание строки до символа новой строки

    printf("Enter the substring to search: ");
    scanf(" %[^\n]", sub);

    // Поиск подстроки
    result = ownStrstr(str, sub);

    if (result) {
        printf("Substring found at index: %ld\n", result - str);
    }
    else {
        printf("Substring not found.\n");
    }

    return 0;
}