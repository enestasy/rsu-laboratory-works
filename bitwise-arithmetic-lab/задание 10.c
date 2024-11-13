//.Написать макросы циклического сдвига в 2 𝑝 разрядном целом числе на 𝑛 бит влево и вправо.

#include <stdio.h>
#include <string.h>

#define toRight(a, n) ((a >> n) | (a << (8 * sizeof(a) - n)))
#define toLeft(a, n) ((a << n) | (a >> (8 * sizeof(a) - n)))


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


//Преобразование из строки с двоичным числом в десятичное число
int fromStrokeToNum(const char * binaryStroke) {  // const char * указывает на указатель на массив символов
    int decimalNum = 0;
    int length = strlen(binaryStroke);
    
    for (int i = 0; i < length; i++) {
        if (binaryStroke[length - 1 - i] == '1') { //Если символ строки равен "1", то добавляется степень двойки, соответствующая индексу
            decimalNum += degreesOfTwo(i); 
        }
    }

    return decimalNum;
}

//Перевод в двоичную запись
void bprintf(unsigned int n) {

    unsigned int i, j = 1 << 31;

    for (i = 0; i < 32; i++) {
        printf("%d", n & j ? 1 : 0);
        j >>= 1;
    }
}


int main() {
    int shift, decimalNum, shiftedToLeft, shiftedToRight;
    char binaryNum[33];

    printf("Enter binary number for the shift: ");
    scanf("%32s", binaryNum);

    printf("\nEnter the amount of the shift: ");
    scanf("%d", &shift);

    decimalNum = fromStrokeToNum(binaryNum);
    shiftedToLeft = toLeft(decimalNum, shift);
    shiftedToRight = toRight(decimalNum, shift);

    printf("\nShifted to left: ");
    bprintf(shiftedToLeft);

    printf("\nShifted to right: ");
    bprintf(shiftedToRight);
    
    printf("\n");

    return 0;
}
