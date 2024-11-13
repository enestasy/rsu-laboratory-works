//8.Задан числовой массив. Переписать в новый массив чётные числа.

#include <stdio.h>

int main() {
    int length;

    printf("Enter the length of the array: ");
    scanf("%d", &length);

    int numbers[length];

    printf("Enter the numbers in the array:\n");
    for (int i = 0; i < length; i++) {
        printf("numbers[%d]: ", i);
        scanf("%d", &numbers[i]);
    }

    // подсчет количества чётных чисел
    int evenCount = 0;
    for (int i = 0; i < length; i++) {
        if (numbers[i] % 2 == 0) { // проверка на четность
            evenCount++;
        }
    }

    int evenNumbers[evenCount];

    // заполнение нового массива четными числами
    for (int i = 0, j = 0; i < length; i++) {
        if (numbers[i] % 2 == 0) {
            evenNumbers[j] = numbers[i];
            j++;
        }
    }

    printf("Even numbers:\n");
    for (int i = 0; i < evenCount; i++) {
        printf("%d ", evenNumbers[i]);
    }
    printf("\n");

    return 0;
}
