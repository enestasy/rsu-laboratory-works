/* Задание 4.

Реализовать функцию с переменным числом аргументов, принимающую в качестве входных
параметров подстроку и пути к файлам. Необходимо чтобы для каждого файла функция
производила поиск всех вхождений переданной подстроки в содержимом этого файла. В
подстроку могут входить любые символы (обратите внимание, что в подстроку также могут
входить символы пробела, табуляций, переноса строки, в неограниченном количестве; пустая
подстрока также допустима). При реализации запрещается использование функций из
заголовочного файла string.h. Продемонстрируйте работу функции, также организуйте наглядный
вывод результатов работы функции: для каждого файла, путь к которому передан как параметр
Вашей функции, для каждого вхождения подстроки в содержимое файла необходимо вывести
номер строки (индексируется с 1) и номер символа в строке файла (индексируется с 1), начиная с
которого найдено вхождение подстроки.

*/
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

#define NO_DATA 2
#define OPEN_ERROR 3
#define MEMORY_ALLOCATION_ERROR 4
#define NOT_FOUND -1
#define INITIAL_BUFFER_SIZE 128

int find_substring_pos(const char *line, const char *substr) {
    if (substr == NULL || *substr == '\0') {
        return 0;
    }

    for (int i = 0; line[i] != '\0'; i++) {
        int j = 0;
        while (line[i + j] == substr[j] && substr[j] != '\0') {
            j++;
        }
        if (substr[j] == '\0') {
            return i + 1;
        }
    }

    return NOT_FOUND;
}

int find_occurrences(const char *f_string, ...) {
    if (f_string == NULL) {
        return NO_DATA;
    }

    va_list ap;
    va_start(ap, f_string);

    const char *file_path = va_arg(ap, const char *);
    if (file_path == NULL) {
        va_end(ap);
        return NO_DATA;
    }

    while (file_path != NULL) {

        FILE *current_file = fopen(file_path, "r");
        if (current_file == NULL) {
            va_end(ap);
            return OPEN_ERROR;
        }

        int buffer_size = INITIAL_BUFFER_SIZE;
        char *line = malloc(buffer_size * sizeof(char));
        if (line == NULL) {
            fclose(current_file);
            va_end(ap);
            return MEMORY_ALLOCATION_ERROR;
        }

        int line_number = 1;
        while (fgets(line, buffer_size, current_file) != NULL) {
            while (line[strlen(line) - 1] != '\n' && !feof(current_file)) {
                buffer_size *= 2;
                char *temp = realloc(line, buffer_size * sizeof(char));
                if (temp == NULL) {
                    free(line);
                    fclose(current_file);
                    va_end(ap);
                    return MEMORY_ALLOCATION_ERROR;
                }
                line = temp;

                if (fgets(line + strlen(line), buffer_size - strlen(line), current_file) == NULL) {
                    break;
                }
            }

            int position = find_substring_pos(line, f_string);
            if (position != NOT_FOUND) {
                printf("File: %s, Line: %d, Position: %d\n", file_path, line_number, position);
            }

            line_number++;
        }

        free(line);
        fclose(current_file); 
        
        file_path = va_arg(ap, const char *);
    }

    va_end(ap);
    return 0;
}

int main() {
    int result = find_occurrences("LABY", "file1.txt", "file2.txt", NULL);
    return 0;
}