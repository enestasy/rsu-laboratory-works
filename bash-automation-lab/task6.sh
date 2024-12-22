# Задание 6. Для списка переданных файлов создайте жёсткие ссылки с тем
# же именем, но добавленным расширением «.1». Если таковые
# ссылки уже существуют, то расширение увеличивается на 1:
# «.2». Если есть все файлы с расширением до «.9» включительно, то новые ссылки не создаются. Предусмотреть ключ «-r»,
# который удаляет все жёсткие ссылки на указанные из списка
# файлы c разрешениями от «.1» до «.9».

#!/bin/bash

ERROR_LOG="error_log_task6.txt"
REMOVE_LINKS=false

while [[ $# -gt 0 ]];
do
    case "$1" in
        -r)
            REMOVE_LINKS=true
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
        -h)
            echo "Usage: $0 [-r] [-e error_log_file] file1 [file2 ...]"
            echo "  -r          Remove hard links with extensions .1 to .9"
            echo "  -e          Specify a file to log errors"
            echo "  file1 ...   Files to process"
            exit 0
            ;;
        *)
            FILES+=("$1")
            shift
            ;;
    esac
done

if [[ ${#FILES[@]} -eq 0 ]];
then
    echo "Error: No files specified" >> "$ERROR_LOG"
    exit 1
fi

create_hard_link() {
    local file="$1"
    local base_name=$(basename "$file")
    local ext=1

    while [[ -e "$base_name.$ext" && $ext -le 9 ]];
    do
        ((ext++))
    done

    if [[ $ext -le 9 ]];
    then
        ln "$file" "$base_name.$ext"
        echo "Created hard link: $base_name.$ext"
    else
        echo "Error: Maximum number of hard links (.1 to .9) reached for '$file'" >> "$ERROR_LOG"
    fi
}

remove_hard_links() {
    local file="$1"
    local base_name=$(basename "$file")

    for ext in {1..9};
    do
        if [[ -e "$base_name.$ext" ]];
        then
            rm "$base_name.$ext"
            echo "Removed hard link: $base_name.$ext"
        fi
    done
}

for file in "${FILES[@]}";
do
    if [[ ! -f "$file" ]];
    then
        echo "Error: '$file' is not a valid file" >> "$ERROR_LOG"
        continue
    fi

    if $REMOVE_LINKS;
    then
        remove_hard_links "$file"
    else
        create_hard_link "$file"
    fi
done
