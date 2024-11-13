//6.Дана квадратная матрица произвольного размера. Необходимо найти определитель
//матрицы.
#include <stdio.h>
#include <string.h>

int determinantFinding(int *matrix, int length) {
    int determinant = 0;

    // Если матрица первого порядка, то определитель равен ее элементу
    if (length == 1) {
        return matrix[0];
    }

    // Если матрица второго порядка, то определитель равен разности произведений на главной диагонали и побочной
    if (length == 2) {
        return (matrix[0] * matrix[3]) - (matrix[1] * matrix[2]);
    }

    // Если матрица больше 2-го порядка, то определитель высчитывается по формуле
    for (int i = 0; i < length; i++) { //цикл проходит по каждому элементу первой строки матрицы
        
        // Создаём подматрицу (исключает верхнюю строку и левый столбец)
        int submatrix[length - 1][length - 1];

        
        for (int j = 1; j < length; j++) {
            for (int k = 0; k < length; k++) {
                if (k < i) {
                    submatrix[j - 1][k] = matrix[j * length + k]; //размещение элемента в строке подматрицы
                } else if (k > i) {
                    submatrix[j - 1][k - 1] = matrix[j * length + k]; //если текущий столбец k находится после исключаемого столбца i, тогда элемент также копируется, но он должен быть сдвинут влево на одну позицию, чтобы не оставалось пробелов
                }
            }
        }

        // Вычисляем определитель с учётом знака
        determinant += (i % 2 == 0 ? 1 : -1) * matrix[i] * determinantFinding((int *)submatrix, length - 1);

        // (i % 2 == 0 ? 1 : -1) Если индекс элемента чётный, знак положительный; если нечётный — отрицательный

        // matrix[i] - текущий элемент первой строки матрицы, по которому происходит разложение

    }

    return determinant;
}

int main() {
    
    int length;

    printf("Enter the size of the square matrix: ");
    scanf("%d", &length);

    int matrix[length * length];

    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length; j++) {
            printf("Enter the number in row %d and column %d: ", i + 1, j + 1);
            scanf("%d", &matrix[i * length + j]);
        }
    }
    
    int determinant = determinantFinding(matrix, length);

    printf("The determinant of the matrix is: %d\n", determinant);

    return 0;
}
