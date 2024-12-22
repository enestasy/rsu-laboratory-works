# Задание 8. Выведите все подкаталоги в указанном каталоге отсортировав их по размеру, занимаемому их файлами.


#!/bin/bash


ERROR_LOG="error_log_task8.txt"
TARGET_DIR="."

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
            echo "Usage: $0 [-e error_log_file] directory"
            echo "  -e          Specify a file to log errors"
            echo "  directory   Directory to check subdirectories"
            exit 0
            ;;
        *)
            TARGET_DIR="$1"
            shift
            ;;
    esac
done

if [[ ! -d "$TARGET_DIR" ]];
then
    echo "Error! Directory '$TARGET_DIR' does not exist" >> "$ERROR_LOG"
    exit 1
fi

find "$TARGET_DIR" -type d -exec du -sh {} \; | sort -h
