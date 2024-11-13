//5.Дан массив целых чисел типа int. Реализовать алгоритм двоичного поиска элемента,
//значение которого запрашивается у пользователя из стандартного потока ввода.

#include <stdio.h>
#include <string.h>

void bubble_sort(int *numbers, int count) { //Сортировка массива
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

int binarySearch(int *numbers, int searchingNum, int length) {
    int left = 0; //Левая каретка
    int right = length - 1; //Правая каретка

    while (left <= right) {
        int mid = (left + right) / 2;
        
        if (numbers[mid] == searchingNum) { //Возвращаем число если оно найдено
            return mid;
        }
        
        if (searchingNum > numbers[mid]) { //Если число больше чем среднее, то ищем в правой части
            left = mid + 1;
        }

        else {
            right = mid - 1; //Если число меньше чем среднее, то ищем в левой части
        }
    }

    return -1; //Возвращает -1, если число не найдено
}

int main() {
    int length, searchingNum;

    printf("Enter the length of the array: ");
    scanf("%d", &length);
    
    int numbers[length];

    printf("Enter the numbers in the array:\n");
    for (int i = 0; i < length; i++) {
        printf("[%d]: ", i);
        scanf("%d", &numbers[i]);
    }

    bubble_sort(numbers, length);

    printf("Sorted array:\n");
    for (int i = 0; i < length; i++) {
        printf("%4d", numbers[i]);
    }
    printf("\n");

    printf("Enter the number you want to search: ");
    scanf("%d", &searchingNum);
    
    int result = binarySearch(numbers, searchingNum, length);

    if (result == -1) {
        printf("The number %d is not found in the array\n", searchingNum);
    } else {
        printf("The number %d is at index %d\n", searchingNum, result);
    }

    return 0;
}
