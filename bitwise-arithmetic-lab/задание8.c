//Найти максимальную степень 2 на которую делится данное целое число. Примечание. Операторами цикла пользоваться нельзя.

//Вариант 1
#include <stdio.h>

int max_divider(int number, int * degree) {
    if (number % 2 != 0) {
        return 1;
    } else {
        (*degree)++;
        return 2 * max_divider(number / 2, degree);
    }
}

int main() {
    int number, degree = 0, divider;
    
    printf("Enter number: ");
    scanf("%d", &number);
    
    if (number == 0) {
        printf("The number cannot be zero.\n");
        return 1;
    }
    
    divider = max_divider(number, &degree);
    
    printf("The largest power-of-two divisor is: %d\n", divider);
    printf("The degree of the divisor is: %d\n", degree);

    return 0;
}


//Вариант 2 (работает не всегда)

/*
#include <stdio.h>
#include <math.h>

int main() {
    int number, divider;
    
    printf("Enter number: ");
    scanf("%d", &number);
    if (number == 0) {
        printf("The number cannot be zero.\n");
    }
    // Узнаём максимальную степень двойки на которую делится число
    divider = number & (-number);
    printf("The divider of your number is: %d\n", divider);
    
    if (divider != 0) { //аргумент логарифма не может быть равен 0
        printf("The degree of the divisor is: %.0f\n", log2(divider));
    }

    return 0;
}
*/
