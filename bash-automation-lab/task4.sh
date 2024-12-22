# Задание 4. Определите список каталогов, в которых присутствует файл
# с указанным именем. Начальный каталог указывается после флага «-d»,
# если не указан, то используется текущий каталог по умолчанию.

#!/bin/bash

MAIN_DIR="."
FILE_NAME=""
ERROR_LOG="error_log_task4.txt"

while [[ $# -gt 0 ]];
do
    case "$1" in
    -d)
        if [[ -n $2 ]];
        then
            MAIN_DIR="$2"
            shift
        else
            echo "Error! There is no directory" >> "$ERROR_LOG"
            exit 1
        fi
        ;;
    -h)
        echo "Usage: $0 [-d directory] [-e error_log_file] file_name"
        echo "  -d directory     Specify the starting directory (default is the current directory)"
        echo "  -e error_log     Specify the error log file"
        echo "  file_name        The name of the file to search for"
        exit 0
        ;;

    -e)
        if [[ -n $2 ]];
        then
            ERROR_LOG="$2"
            shift
        else
            echo "Error! No error log file specified" >> "$ERROR_LOG"
            exit 1
        fi
        ;;
    *)
        FILE_NAME="$1"
        ;;
    esac
    shift
done

if [[ -z $FILE_NAME ]];
then
    echo "Error! No file name specified" >> "$ERROR_LOG"
    exit 1
fi

if [[ ! -d "$MAIN_DIR" ]];
then
    echo "Error! Directory '$MAIN_DIR' does not exist" >> "$ERROR_LOG"
    exit 1
fi

RESULTS=$(find "$MAIN_DIR" -type f -name "$FILE_NAME" 2>>"$ERROR_LOG")

if [[ -n $RESULTS ]];
then
    echo "File '$FILE_NAME' found in the following directories:"
    echo "$RESULTS" | xargs -n 1 dirname | sort -u
else
    echo "File '$FILE_NAME' not found in the directory '$MAIN_DIR' and its subdirectories." >> "$ERROR_LOG"
fi
