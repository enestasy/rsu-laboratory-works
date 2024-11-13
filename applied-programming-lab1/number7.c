//7.Задан числовой массив. Переписать в новый массив числа, стоящие на нечётных позициях.

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

    // подсчет количества элементов на нечётных позициях
    int oddCount = length / 2;
    
    if (length % 2 != 0) {
        oddCount += 1; // если длина нечётная, +1 к количеству
    }
    
    int oddNumbers[oddCount]; // новый массив для хранения элементов

    // заполнение нового массива числами с нечётных позиций
    for (int i = 0, j = 0; i < length; i++) {
        if (i % 2 != 0) {
            oddNumbers[j] = numbers[i];
            j++;
        }
    }

    printf("Numbers at odd positions:\n");
    for (int i = 0; i < oddCount; i++) {
        printf("%d ", oddNumbers[i]);
    }
    printf("\n");

    return 0;
}
