/*B) Получить биты из целого числа длиной 𝑙𝑒𝑛 битов, находящиеся
между первыми 𝑖 битами и последними 𝑖 битами. Пример. Пусть
есть 12-ти разрядное целое число, представленное в двоичной
системе счисления 100011101101. Получим биты находящиеся
между первыми 3 и последними 3 битами: 011101. */

#include <stdio.h>
#include <string.h>

// Удаление крайних цифр числа
int removeExtremeDigits(int num, int i) {

    char strNum[16];
    sprintf(strNum, "%d", num); //Число => строка
    
    int len = strlen(strNum);

    if (2 * i >= len) {
        printf("The number of extreme digits is too large\n");
        return 1;
    }

    // Строка для оставшихся цифр
    char resultStr[16];
    strncpy(resultStr, strNum + i, len - 2 * i); 
    resultStr[len - 2 * i] = '\0';

    int result;
    sscanf(resultStr, "%d", &result); //Строка => число

    return result;
}

int main() {
    int num, i, result;
    
    printf("Enter number: ");
    scanf("%d", &num);

    printf("\nEnter the number of extreme digits to be removed: ");
    scanf("%d", &i);

    result = removeExtremeDigits(num, i);

    printf("The result after removing extreme digits is: %d\n", result);

    return 0;
}
