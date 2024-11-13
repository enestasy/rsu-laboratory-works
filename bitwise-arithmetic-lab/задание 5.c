//Поменять местами 𝑖 −ый и 𝑗 −ый биты в числе 𝑎. Числа 𝑖 и j предварительно считать с клавиатуры.

#include <stdio.h>


//Функция по определению необходимого бита
int getBit(int a, unsigned int k) {
    int i;
    if (k < sizeof(int) * 8) {
    for (i = 0; i < k; i ++) {
        a = a / 2;
    }

    return a % 2;
    }

    else {
        printf("Error! Index out of range");
        return -1;
    }
    printf("\n");
}

//Перевод в двоичную запись
void bprintf(unsigned int n) {
    unsigned int i, j = 1 << 31;
    for (i = 0; i < 32; i++) {
        printf("%d", n & j ? 1 : 0);
        j >>= 1;
    }
}

//Вычисление степеней двойки
int degreesOfTwo(unsigned int n) {
    int result = 1;

    if (n == 0) { 
        return 1;
    } else {
        for (int i = 1; i <= n; i++) {
            result = result * 2;
        }
        return result;
    }
}

int changeBit(int n, int i, int j) {
    int r;
    r = n ^ (degreesOfTwo(i)) ^ (degreesOfTwo(j)); //К числу применяется xor с теми индексами, которые ввёл пользователь
    return r;
}


int main() {
    int num, firstBit, secondBit, i, j;
    printf("Enter number: ");
    scanf("%d", &num);
    printf("Binary version of the number: ");
    bprintf(num);
    printf("\nEnter the index of the first bit: ");
    scanf("%d", &i);
    printf("Enter the index of the second bit: ");
    scanf("%d", &j);
    firstBit = getBit(num, i);
    secondBit = getBit(num, j);

    if (firstBit == secondBit) { //Если биты, которые меняем, одинаковые, выводим изначальное число
        printf("The resulting number is: %d", num);
        printf("\nBinary version of the resulting number: ");
        bprintf(num);
    }
    
    else // В ином случае меняем биты
    {
        printf("The resulting number is: %d", changeBit(num, i, j));
        printf("\nBinary version of the resulting number: ");
        bprintf(changeBit(num, i, j));

    }

    return 0;
}
