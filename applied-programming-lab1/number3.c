//3.Реализовать функцию, меняющую местами значения двух чисел типа int. Входными параметрами функции являются указатели типа int *.
#include <stdio.h>

void changeNums(int *num1, int *num2) {
    int temp = *num1; // Сохраняем значение, на которое указывает num1
    *num1 = *num2;    // Записываем значение num2 в num1
    *num2 = temp;     // Записываем сохранённое значение num1 в num2
}

int main() {
    int first, second;

    printf("Enter two numbers: ");
    scanf("%d%d", &first, &second);

    // Передаём адреса переменных в функцию
    changeNums(&first, &second);

    printf("The result is: %d %d\n", first, second);

    return 0;
}
