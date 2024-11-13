//17.Реализовать функцию конкатенации строк, аналогичную стандартной функции strcat.

#include <stdio.h>
#include <stdlib.h>

char* ownStrcat(char* dest, const char* src) {
    char* originalDest = dest; // сохранение указателя на начало первой строки

    //Указатель перемещается в конец
    while (*dest != '\0') {
        dest++;
    }

    // копирование второй строки после первой
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    
    *dest = '\0'; // завершение новой строки завершающим нулём

    return originalDest; // возврат указателя на место
}

int main() {
    char str1[100];
    char str2[50];

    printf("Enter the first string: ");
    fgets(str1, sizeof(str1), stdin);

    str1[strcspn(str1, "\n")] = '\0';

    printf("Enter the second string: ");
    fgets(str2, sizeof(str2), stdin);

    
    str2[strcspn(str2, "\n")] = '\0';

    ownStrcat(str1, str2); 

    printf("Concatenated string: %s\n", str1);

    return 0;
}