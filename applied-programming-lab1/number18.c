//18.Дана квадратная матрица. Реализовать алгоритм транспонирования матрицы.

#include <stdio.h>

#define MAX_SIZE 100 // Максимальный размер матрицы

void transposeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) { //перебор строк от 0 до size - 1
        for (int j = i + 1; j < size; j++) { //перебор столбцов, начиная с i + 1
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i]; //изменение места элементов
            matrix[j][i] = temp;
        }
    }
}

void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int size;
    int matrix[MAX_SIZE][MAX_SIZE];

    printf("Enter the size of the square matrix: ");
    scanf("%d", &size);

    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("Enter the element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("The originsl matrix:\n");
    printMatrix(matrix, size);

    transposeMatrix(matrix, size);

    printf("Transposed matrix:\n");
    printMatrix(matrix, size);

    return 0;
}
