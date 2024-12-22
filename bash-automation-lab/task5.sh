# Задание 5.Проверить список указанных каталогов (передаются списком
# аргументов без указания ключа) и вывести список всех файлов
# (с полным относительно текущего каталога путём) с большим
# относительно указанного количества слов в каждом из них.

#!/bin/bash

ERROR_LOG="error_log_task5.txt"
MIN_WORDS=10

while [[ $# -gt 0 ]];
do
    case "$1" in
        -e)
            if [[ -n $2 ]];
            then
                ERROR_LOG="$2"
                shift 2
            else
                echo "Error! No error log file specified" >> "$ERROR_LOG"
                exit 1
            fi
            ;;
        -h)
            echo "Usage: $0 [-e error_log_file] min_word_count directory ..."
            echo "  -e error_log_file  Specify the file for logging errors (default: 'error_log_task5.txt')"
            echo "  -h                  Display this help message"
            echo "  min_word_count      Minimum number of words a file should have to be listed"
            echo "  directory           One or more directories to search for files"
            exit 0
            ;;
        *)
            MIN_WORDS=$1
            shift
            ;;
    esac
done

if [[ -z $MIN_WORDS ]];
then
    echo "Error! No minimum word count specified" >> "$ERROR_LOG"
    exit 1
fi

for directory in "$@";
do
    if [[ -d $directory ]];
    then
        find "$directory" -type f | while read -r file;
        do
            word_count=$(wc -w < "$file")
            if [[ $word_count -gt $MIN_WORDS ]];
            then
                echo "File '$file' has more than $MIN_WORDS words."
            fi
        done
    else
        echo "Directory '$directory' not found" >> "$ERROR_LOG"
    fi
done
