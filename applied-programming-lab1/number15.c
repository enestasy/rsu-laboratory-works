//15.Задана строка символов. Используя указатели, переписать строку так, чтобы в начале строки были символы цифр, затем символы букв латинского алфавита, а в самом концепрочие символы; порядок следования цифр/букв латинского алфавита/прочих символов при этом сохранить.

#include <stdio.h>
#include <ctype.h>

void rearrangeString(char *str) {
    char *temp = str;//перемещение по строке
    char digits[100];
    char letters[100];
    char others[100];

    int digit_count = 0;
    int letter_count = 0;
    int other_count = 0;

    // Перемещение указателя по строке
    while (*temp != '\0') {
        if (isdigit(*temp)) {
            digits[digit_count++] = *temp;//сохранение цифры
        } else if (isalpha(*temp)) {
            letters[letter_count++] = *temp;//сохранение буквы
        } else {
            others[other_count++] = *temp;//сохранение всего остального
        }
        temp++;
    }

    // завершаем массивы нулями
    digits[digit_count] = '\0';
    letters[letter_count] = '\0';
    others[other_count] = '\0';

    // объединение трёх массивов

    temp = str; 
    for (int i = 0; i < digit_count; i++) {
        *temp++ = digits[i]; // цифры
    }


    for (int i = 0; i < letter_count; i++) {
        *temp++ = letters[i]; //буквы
    }


    for (int i = 0; i < other_count; i++) {
        *temp++ = others[i]; // другое
    }

    *temp = '\0';
}

int main() {
    char str[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    str[strcspn(str, "\n")] = '\0'; //убираем лишний перенос на новую строку

    rearrangeString(str);

    printf("Rearranged string: %s\n", str);

    return 0;
}
