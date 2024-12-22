# Задание 9. Удалите все файлы согласно списку файлов, находящегося в указанном файле.

#!/bin/bash

ERROR_LOG="error_log_task9.txt"
FILE_LIST=""

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
        -f)
            if [[ -n $2 ]];
            then
                FILE_LIST="$2"
                shift 2
            else
                echo "Error! No file list specified" >> "$ERROR_LOG"
                exit 1
            fi
            ;;
        -h)
            echo "Usage: $0 [-e error_log_file] -f file_with_list"
            echo "  -e          Specify a file to log errors"
            echo "  -f          File containing the list of files to delete"
            exit 0
            ;;
        *)
            echo "Unknown argument: $1" >> "$ERROR_LOG"
            exit 1
            ;;
    esac
done

if [[ ! -f "$FILE_LIST" ]];
then
    echo "Error! File list '$FILE_LIST' does not exist" >> "$ERROR_LOG"
    exit 1
fi

while read -r file;
do
    if [[ -e "$file" ]];
    then
        rm "$file"
        echo "Removed file: $file"
    else
        echo "File '$file' not found" >> "$ERROR_LOG"
    fi
done < "$FILE_LIST"
