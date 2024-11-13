//Обнулить младшие k бит в заданном слове

#include <stdio.h>

// Функция для обнуления младших битов через сдвиг
int clearBitsShift(int word, int k) {
    // Сдвигаем вправо на k бит, убирая младшие биты, затем сдвигаем обратно влево
    return (word >> k) << k;
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
    int k, word;

    printf("Enter number: ");
    scanf("%d", &word);
    bprintf(word);
    printf("\n");

    printf("Enter the number of low-order bits to clear: ");
    scanf("%d", &k);

    // Очищаем младшие биты с использованием сдвига
    printf("Result after clearing bits: %d\n", clearBitsShift(word, k));
    bprintf(clearBitsShift(word, k));
    printf("\n");

    return 0;
}
