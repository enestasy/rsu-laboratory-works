//Установить 𝑘 −ый бит числа �

#include <stdio.h>

//Установка бита
int setBit(int n, int d) {
    return ((1 << d) | n);
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
    int a, k;

    printf("Enter number: ");
    scanf("%d", &a);

    printf("Binary number: ");
    bprintf(a);
    printf("\n");
    
    printf("Enter bit to set: ");
    scanf("%d", &k);
    printf("%d\n", setBit(a, k));
    printf("Binary number: ");
    bprintf(setBit(a, k));
    printf("\n");

    return 0;
}
