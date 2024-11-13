//2.Реализовать алгоритм “переворота” (reverse) символьной строки.
#include <stdio.h>

#define MAX_LENGTH 100  // Максимальная длина строки

int main() {
    char buffer[MAX_LENGTH];  // Массив фиксированной длины
    int i = 0;
    char c;

    printf("Введите строку (до %d символов): ", MAX_LENGTH - 1);

    // Чтение символов до конца строки или достижения максимального размера
    while ((c = getchar()) != '\n' && c != EOF && i < MAX_LENGTH - 1) {
        buffer[i] = c;
        i++;
    }

    buffer[i] = '\0';  // Завершаем строку нулевым символом

    printf("Введённая строка: %s\n", buffer);

    return 0;
}
