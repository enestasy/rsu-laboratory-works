/* Задание 3.

Реализовать функцию с переменным числом аргументов, выполняющую возврат ресурсов в
контекст запроса:
● возврат в кучу ранее выделенной динамической памяти
● закрывающую ранее открытые под файлы файловые переменные
Для конфигурирования действий по возврату ресурса, для каждого ресурса в функцию
необходимо передать два параметра: указатель на ресурс и флаг действия. При получении из
списка аргументов переменной длины указателя на ресурс со значением NULL, обработка списка
аргументов переменной длины должна быть прекращена. Передача количества аргументов в
функцию при этом не допускается. Продемонстрируйте работу реализованной функции

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#define FREE_MEMORY 1
#define CLOSE_FILE 2
#define INPUT_ERROR 3
#define OPEN_ERROR 4

void free_resources(void *res_ptr, ...) {
    if (res_ptr == NULL) {
        return;
    }

    va_list args;
    va_start(args, res_ptr);

    while (res_ptr != NULL) {
        int action_flag = va_arg(args, int);

        if (action_flag == FREE_MEMORY) {
            free(res_ptr);
        } else if (action_flag == CLOSE_FILE) {
            fclose((FILE *)res_ptr);
        } else {
            return INPUT_ERROR;
        }

        res_ptr = va_arg(args, void *);
    }

    va_end(args);
}

int main() {

    int *data = (int *)malloc(5 * sizeof(int));

    if (data == NULL) {
        return OPEN_ERROR;
    }

    FILE *file = fopen("test.txt", "w");

    if (file == NULL) {
        free(data);
        return OPEN_ERROR;
    }
    
    free_resources(data, FREE_MEMORY, file, CLOSE_FILE, NULL);

    return 0;
}