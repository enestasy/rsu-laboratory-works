//14.В текстовом файле задан целочисленный массив. Разделительный символ между значениями– пробел. Файл корректный. Необходимо считать данные из файла, заполнить массив и найти в этом массиве максимальный и минимальные элементы. При реализации используйте функцию из задания 4.

#include <stdio.h>

#define MAX_SIZE 100 // Максимальный размер массива

// Функция для нахождения максимального значения в массиве
int findMax(int *numbers, int arrayValue) {
    int maximalValue = numbers[0];
    for (int i = 1; i < arrayValue; i++) {
        if (numbers[i] > maximalValue) {
            maximalValue = numbers[i];
        }
    }
    return maximalValue;
}

// Функция для нахождения минимального значения в массиве
int findMin(int *numbers, int arrayValue) {
    int minimalValue = numbers[0];
    for (int i = 1; i < arrayValue; i++) {
        if (numbers[i] < minimalValue) {
            minimalValue = numbers[i];
        }
    }
    return minimalValue;
}

int main() {
    FILE *file = fopen("1.txt", "r"); // Открываем файл для чтения
    if (file == NULL) {
        printf("File can`t be opened.\n");
        return -1;
    }

    int array[MAX_SIZE];
    int size = 0;

    while (fscanf(file, "%d", &array[size]) == 1) {
        size++;
        if (size >= MAX_SIZE) {
            printf("array is full!!@\n");
            break; // прекращение считывания, если достигнут максимальный размер
        }
    }

    fclose(file);

    if (size == 0) {
        printf("No values were read from the file.\n");
        return -1;
    }

    int max = findMax(array, size);
    int min = findMin(array, size);

    printf("Maximum value: %d\n", max);
    printf("Minimum value: %d\n", min);

    return 0;
}
