//19. Дана квадратная матрица. Реализовать алгоритм нахождения обратной матрицы.

#include <stdio.h>
#include <string.h>

#define MAX 10

float determinantFinding(float matrix[MAX][MAX], int length) {
    float determinant = 0;

    // Если матрица первого порядка
    if (length == 1) {
        return matrix[0][0];
    }

    // Если матрица второго порядка
    if (length == 2) {
        return (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
    }

    // Для матриц больше 2-го порядка
    for (int i = 0; i < length; i++) {
        float submatrix[MAX][MAX];

        // подматрица
        for (int j = 1; j < length; j++) {
            int subCol = 0;
            for (int k = 0; k < length; k++) {
                if (k != i) {
                    submatrix[j - 1][subCol] = matrix[j][k];
                    subCol++;
                }
            }
        }

        // Вычисление определителя с учетом знака
        determinant += (i % 2 == 0 ? 1 : -1) * matrix[0][i] * determinantFinding(submatrix, length - 1);
    }

    return determinant;
}


int inverseMatrix(float matrix[MAX][MAX], int length, float inverse[MAX][MAX]) {
    float determinant = determinantFinding(matrix, length);

    if (determinant == 0) {
        printf("The inverse matrix does not exist (determinant is 0).\n");
        return -1; 
    }

    float cofactor[MAX][MAX]; // создание матрицы алгебраических дополнений = МАД
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length; j++) {
            float submatrix[MAX][MAX];
            int subRow = 0;

            // создание подматрицы для алгебраического дополнения
            for (int x = 0; x < length; x++) {
                if (x != i) {
                    int subCol = 0;
                    for (int y = 0; y < length; y++) {
                        if (y != j) {
                            submatrix[subRow][subCol] = matrix[x][y];
                            subCol++;
                        }
                    }
                    subRow++;
                }
            }
            // вычисление алгебраического дополнения
            cofactor[i][j] = ((i + j) % 2 == 0 ? 1 : -1) * determinantFinding(submatrix, length - 1);
        }
    }

    // Транспонирование МАД и деление на определитель
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length; j++) {
            inverse[i][j] = cofactor[j][i] / determinant; // Транспонирование и деление на определитель
        }
    }

    return 0;
}

void printMatrix(float matrix[MAX][MAX], int length) {
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length; j++) {
            printf("%0.2f ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int length;
    float matrix[MAX][MAX];
    float inverse[MAX][MAX];

    printf("Enter the size of the square matrix: ");
    scanf("%d", &length);

    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length; j++) {
            printf("Enter element [%d][%d]: ", i + 1, j + 1);
            scanf("%f", &matrix[i][j]);
        }
    }
    
    printf("Original matrix:\n");
    printMatrix(matrix, length);

    if (inverseMatrix(matrix, length, inverse) == 0) {
        printf("Inverse matrix:\n");
        printMatrix(inverse, length);
    }

    return 0;
}
    