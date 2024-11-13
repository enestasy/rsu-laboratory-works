//Поменять местами байты в заданном 32-х разрядном целом числе. Перестановка задаётся пользователем.

#include<math.h>
#include <stdio.h>

unsigned int getByte(int n, int k) // Получение байта
{
    return ((n & (255 << (k * 8))) >> (k * 8));
}

unsigned int clearByte(unsigned int n, int k) // Очистка байта
{
    return (n & (~(255 << (k * 8))));
}

void bprintf(unsigned int n) { // Двоичная запись числа
    unsigned int i, j = 1 << 31;
    for (i = 0; i < 32; i++) {
        printf("%d", n & j ? 1 : 0);
        j >>= 1;
    }
    printf("\n");
}

unsigned int exchangeByte(unsigned int n, int k, int l)
{
    unsigned int a, b;

    // Получаем байты k и l
    a = getByte(n, k);
    printf("a=");
    bprintf(a);
    
    printf("\n");
    
    b = getByte(n, l);
    printf("b=");
    bprintf(b);
    
    printf("\n");

    // Очищаем байты k и l
    n = clearByte(n, k);
    n = clearByte(n, l);

    // Заменяем байты местами
    return (n | (a << (l * 8)) | (b << (k * 8)));
}

int main() 
{
    unsigned int n; // Число, в котором нужно поменять байты местами
    int k;          // Индексы байтов, которые нужно поменять местами
    int l;

    printf("Enter n: ");
    scanf("%u", &n);
    printf("Initial n in binary: ");
    bprintf(n);
    printf("\n");

    printf("Enter index k: ");
    scanf("%d", &k);
    printf("\n");
    
    printf("Enter index l: ");
    scanf("%d", &l);
     printf("\n");

    printf("Before exchange: ");
    bprintf(n);
    
    n = exchangeByte(n, k, l);
    
    printf("After exchange:\n");
    bprintf(n);

    return 0;
}
