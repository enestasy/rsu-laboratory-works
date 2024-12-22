# Задание 7. Создать жёсткие ссылки на каждый из файлов, где обнаружена заданная строка.
# Поиск осуществляется рекурсивно, начиная с указанного каталога.
# Ссылки создаются в текущем каталоге или в указанном после ключа «-o».
# Если указан флаг «-s», то вместо жёстких нужно создать символические ссылки.


#!/bin/bash


ERROR_LOG="error_log_task7.txt"
OUTPUT_DIR="."
SEARCH_STRING=""
CREATE_SYMLINK=false


while [[ $# -gt 0 ]];
do
    case "$1" in
        -s)
            CREATE_SYMLINK=true
            shift
            ;;
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
        -o)
            if [[ -n $2 ]];
            then
                OUTPUT_DIR="$2"
                shift 2
            else
                echo "Error! No output directory specified" >> "$ERROR_LOG"
                exit 1
            fi
            ;;
        -h)
            echo "Usage: $0 [-s] [-e error_log_file] [-o output_dir] search_string directory"
            echo "  -s          Create symbolic links instead of hard links"
            echo "  -e          Specify a file to log errors"
            echo "  -o          Specify the output directory for links"
            echo "  search_string String to search in files"
            echo "  directory   Directory to search files in"
            exit 0
            ;;
        *)
            if [[ -z $SEARCH_STRING ]];
            then
                SEARCH_STRING="$1"
            elif [[ -z $DIRECTORY ]];
            then
                DIRECTORY="$1"
            fi
            shift
            ;;
    esac
done

if [[ -z $SEARCH_STRING || -z $DIRECTORY ]];
then
    echo "Error! No search string or directory specified" >> "$ERROR_LOG"
    exit 1
fi

find "$DIRECTORY" -type f -exec grep -l "$SEARCH_STRING" {} \; | while read -r file;
do
    base_name=$(basename "$file")
    link_name="$OUTPUT_DIR/$base_name.1"
    
    ext=1
    while [[ -e "$link_name" && $ext -le 9 ]];
    do
        ((ext++))
        link_name="$OUTPUT_DIR/$base_name.$ext"
    done

    if [[ $ext -le 9 ]];
    then
        if $CREATE_SYMLINK;
        then
            ln -s "$file" "$link_name"
            echo "Created symbolic link: $link_name"
        else
            ln "$file" "$link_name"
            echo "Created hard link: $link_name"
        fi
    else
        echo "Error! Maximum number of links (.1 to .9) reached for '$file'" >> "$ERROR_LOG"
    fi
done
