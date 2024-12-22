# Задание 2. Определите количество всех строк, находящихся в файлах,
# которые передаются в виде параметров скрипта/функции.

#!/bin/bash

rows_counter=0
all_rows_counter=0
ERROR_LOG="error_log_task2.txt"

while [[ $# -gt 0 ]]; do
    case "$1" in
    -h)
        echo "Usage: $0 [-h] [-e error_log_file] file1.txt file2.txt ..."
        echo "  -h                Display this help message"
        echo "  -e error_log_file Specify the error log file"
        exit 0
        ;;
    -e)
        if [[ -n $2 ]]; then
            ERROR_LOG="$2"
            shift
        else
            echo "Error! No error log file specified" >> "$ERROR_LOG"
            exit 1
        fi
        ;;
    *)
        break
        ;;
    esac
    shift
done

if [ $# -eq 0 ];
then
    echo "Error! No files specified" >> "$ERROR_LOG"
    echo "Usage: $0 file1.txt file2.txt ..."
    exit 1
fi

for file in "$@";
do
    if [ -f "$file" ];
    then
        echo "File '$file' found"
        rows_counter=$(wc -l < "$file")
        all_rows_counter=$((all_rows_counter + rows_counter))
        echo "Number of lines in '$file': $rows_counter"
    else
        echo "Error: The file '$file' was not found" >> "$ERROR_LOG"
    fi
done

echo "Total number of lines in all files: $all_rows_counter"
