//10.Заданы две матрицы произвольного размера. Реализовать алгоритм умножения матриц. В случае, если умножение невозможно, необходимо сообщить пользователю об ошибке

#include <stdio.h>

#define MAX 10

// умножение матриц
void multiplyMatrix(int firstMatrix[MAX][MAX], int secondMatrix[MAX][MAX], int result[MAX][MAX], int rowFirst, int columnFirst, int columnSecond) {
    for (int i = 0; i < rowFirst; i++) { // проход по каждой строке первой матрицы
        for (int j = 0; j < columnSecond; j++) { // для каждой строки первой матрицы проход по каждому столбцу второй матрицы
            result[i][j] = 0;
            for (int k = 0; k < columnFirst; k++) {
                result[i][j] += firstMatrix[i][k] * secondMatrix[k][j];
            }
        }
    }
}

// вывод матрицы
void printMatrix(int matrix[MAX][MAX], int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int firstMatrix[MAX][MAX], secondMatrix[MAX][MAX], result[MAX][MAX];
    int rowFirst, columnFirst, rowSecond, columnSecond;

    printf("Enter rows and columns for the first matrix: ");
    scanf("%d %d", &rowFirst, &columnFirst);

    printf("Enter elements of the first matrix:\n");
    for (int i = 0; i < rowFirst; i++) {
        for (int j = 0; j < columnFirst; j++) {
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%d", &firstMatrix[i][j]);
        }
    }

    printf("Enter rows and columns for the second matrix: ");
    scanf("%d %d", &rowSecond, &columnSecond);

    // проверка возможности умножения
    if (columnFirst != rowSecond) {
        printf("Error!!! Matrices cannot be multiplied.\n");
        return -1;
    }

    printf("Enter elements of the second matrix:\n");
    for (int i = 0; i < rowSecond; i++) {
        for (int j = 0; j < columnSecond; j++) {
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%d", &secondMatrix[i][j]);
        }
    }

    multiplyMatrix(firstMatrix, secondMatrix, result, rowFirst, columnFirst, columnSecond);

    printf("Resultant matrix:\n");
    printMatrix(result, rowFirst, columnSecond);

    return 0;
}
