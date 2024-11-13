//Снять 𝑘 −ый бит числа 𝑎.

#include <stdio.h>

//Снятие бита
int clearBit(int n, int k)
{
    return ((~(1 << k)) & n);
}

//Перевод в двоичную запись
void bprintf(unsigned int n) {
    unsigned int i, j = 1 << 31;
    for (i = 0; i < 32; i++) {
        printf("%d", n & j ? 1 : 0);
        j >>= 1;
    }
}

//Введение пользователем значений и вывод результатов на экран
int main() {
    int a, k;
    printf("Enter number: ");
    scanf("%d", &a);
    printf("Binary number: ");
    bprintf(a);
    printf("\n");
    printf("Enter bit to clear: ");
    scanf("%d", &k);
    printf("Changed number: %d\n", clearBit(a, k));
    printf("Binary number: ");
    bprintf(clearBit(a, k));
    printf("\n");

    return 0;
}
