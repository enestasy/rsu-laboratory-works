/* A) «Склеить» первые 𝑖 битов с последними 𝑖 битами из целого числа
длиной 𝑙𝑒𝑛 битов. Пример. Пусть есть 12-ти разрядное целое число,
представленное в двоичной системе счисления 100011101101.
«Склеим» первые 3 и последние 3 бита, получим 100101. */

#include <stdio.h>
#include <string.h>


int main() {
    int i, len, num;
    printf("Enter length of the number: ");
    scanf("%d", &len);

    char strokeNum[len + 1];

    printf("\nEnter number: ");
    scanf("%d", &num);
    printf("\nEnter the number of extreme bits: ");
    scanf("%d", &i);

    char strokeSum[2 * i + 1]; //Массив для результата

    sprintf(strokeNum, "%d", num);

    if (i > len) {
        printf("The number of extreme characters is greater than the length of the string!"); //Если количетво символов i длиннее строки
        return 1;
    }

    strncpy(strokeSum, strokeNum, i); //запись в strokeSum первых i символов
    
    strncpy(strokeSum + i, strokeNum + len - i, i); //Запись в strokeSum последних i символов
    
    strokeSum[2 * i] = '\0'; //Запись завершающего нуля в последнем индексе

    printf("The result is: %s", strokeSum);

    return 0;
}
