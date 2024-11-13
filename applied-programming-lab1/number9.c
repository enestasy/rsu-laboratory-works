//9.Дан массив значений типа double. Скопировать его в новый массив, удаляя повторяющиеся значения.


#include <stdio.h>

int main() {
    int length;

    printf("Enter the length of the array: ");
    scanf("%d", &length);

    double numbers[length];

    printf("Enter the numbers in the array:\n");
    for (int i = 0; i < length; i++) {
        printf("numbers[%d]: ", i);
        scanf("%lf", &numbers[i]);
    }

    double uniqueNumbers[length];
    int uniqueCount = 0;

    for (int i = 0; i < length; i++) {

        int isDup = 0;

        // проверка на дубликаты
        for (int j = 0; j < uniqueCount; j++) {
            if (numbers[i] == uniqueNumbers[j]) {
                isDup = 1;
                break;
            }
        }
        // если значение уникальное, оно добавляется в новый массив
        if (!isDup) {
            uniqueNumbers[uniqueCount] = numbers[i];
            uniqueCount++;
        }
    }

    printf("Unique numbers:\n");
    for (int i = 0; i < uniqueCount; i++) {
        printf("%.2lf ", uniqueNumbers[i]); //
    }
    printf("\n");

    return 0;
}
