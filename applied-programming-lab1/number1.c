//1.Реализовать алгоритм сортировки пузырьком массива чисел.
#include <stdio.h>

void bubble_sort(int *numbers, int count) {
    int tmp;
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (numbers[j] > numbers[j + 1]) {
                tmp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = tmp;
            }
        }
    }
}

int main() {
    int count;
    printf("Enter how many numbers in array: ");
    scanf("%d", &count);

    int array[count];
    printf("Enter numbers for sort: \n");
    for (int i = 0; i < count; i++) {
        printf("array[%d] = ", i);
        scanf("%d", &array[i]);
    }

    bubble_sort(array, count);
    
    printf("Sorted array:\n");
    for (int i = 0; i < count; i++) {
        printf("%4d", array[i]);
    }
    printf("\n");

    return 0;
}
