//4.Заполнить массив фиксированного размера псевдослучайными целыми числами в диапазоне [-10000..10000]. Реализовать алгоритм поиска максимального и минимального элементов массива, а также индексов этих элементов, за один проход по массиву.
#include <stdio.h>

#define RAND_MAX 10000
#define RAND_MIN -10000

int findMax(int * numbers, int arrayValue) {
int maximalValue = RAND_MIN - 100;
for (int i = 0;  i < arrayValue;  i ++) {
if (numbers[i]  > maximalValue) {
maximalValue  = numbers [i];
}
}
return  maximalValue;
}

int findMin(int * numbers, int arrayValue) {
int minimalValue = RAND_MAX  + 100;
for (int i = 0;  i < arrayValue;  i ++) {
if (numbers[i]  < minimalValue) {
minimalValue  = numbers [i];
}
}
return  minimalValue;
}

int main() {
    int arrayValue, maximum, minimum;
    
    printf("Enter array value: ");
    scanf("%d", &arrayValue);
    
    int numbers[arrayValue];
    
    for (int i = 0; i <  arrayValue; i++ ) {
    int randomNumber = rand() % (RAND_MAX - RAND_MIN + 1)  + RAND_MIN;
    numbers[i] = randomNumber;
    }
    
   printf("Resulted array:\n");
    for (int i = 0; i < arrayValue; i++) {
        printf(" %d", numbers[i]);
    }
    
    maximum = findMax(numbers, arrayValue);
    
    printf ("Maximum number in array is: %d\n", maximum);
    
    minimum = findMin(numbers, arrayValue);
    
    printf ("Minimum number in array is: %d\n", minimum);

    return 0;
}
