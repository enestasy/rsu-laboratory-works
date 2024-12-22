# Задание 11. В файле представлены строки вида
# PathofFile : 0743 : user : users
# Здесь первый параметр – абсолютный путь файла, второй – права доступа, третий – имя пользователя, четвёртый – группа пользователя.
# Только имя файла обязано присутствовать в строке. Если не указан, любой параметр, то используется значение по умолчанию.

#!/bin/bash

ERROR_LOG="error_log_task11.txt"
FILE_LIST=""
MODE_DEFAULT="0644"
USER_DEFAULT=$(whoami)
GROUP_DEFAULT=$(id -gn)

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
        -m)
            if [[ -n $2 ]];
            then
                MODE_DEFAULT="$2"
                shift 2
            else
                echo "Error! No mode specified after -m" >> "$ERROR_LOG"
                exit 1
            fi
            ;;
        -M)
            if [[ -n $2 ]];
            then
                MODE_ALL="$2"
                shift 2
            else
                echo "Error! No mode specified after -M" >> "$ERROR_LOG"
                exit 1
            fi
            ;;
        -u)
            if [[ -n $2 ]];
            then
                USER_DEFAULT="$2"
                shift 2
            else
                echo "Error! No user specified after -u" >> "$ERROR_LOG"
                exit 1
            fi
            ;;
        -U)
            if [[ -n $2 ]];
            then
                USER_ALL="$2"
                shift 2
            else
                echo "Error! No user specified after -U" >> "$ERROR_LOG"
                exit 1
            fi
            ;;
        -g)
            if [[ -n $2 ]];
            then
                GROUP_DEFAULT="$2"
                shift 2
            else
                echo "Error! No group specified after -g" >> "$ERROR_LOG"
                exit 1
            fi
            ;;
        -G)
            if [[ -n $2 ]];
            then
                GROUP_ALL="$2"
                shift 2
            else
                echo "Error! No group specified after -G" >> "$ERROR_LOG"
                exit 1
            fi
            ;;
        -h)
            echo "Usage: $0 [-e error_log_file] -f file_with_list"
            echo "  -e          Specify a file to log errors"
            echo "  -f          File containing the list of files to process"
            echo "  -m          Set default file permission mode (default: 0644)"
            echo "  -M          Set all file permission modes"
            echo "  -u          Set default user (default: current user)"
            echo "  -U          Set all users"
            echo "  -g          Set default group (default: current group)"
            echo "  -G          Set all groups"
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

while IFS=":" read -r path mode user group;
do
    path=$(echo "$path" | xargs)
    mode=$(echo "$mode" | xargs)
    user=$(echo "$user" | xargs)
    group=$(echo "$group" | xargs)

    mode=${mode:-$MODE_DEFAULT}
    user=${user:-$USER_DEFAULT}
    group=${group:-$GROUP_DEFAULT}

    if [[ -n $MODE_ALL ]];
    then
        mode=$MODE_ALL
    fi

    if [[ -n $USER_ALL ]];
    then
        user=$USER_ALL
    fi

    if [[ -n $GROUP_ALL ]];
    then
        group=$GROUP_ALL
    fi

    echo "Setting permissions for file: $path"
    chmod "$mode" "$path"
    chown "$user:$group" "$path"
done < "$FILE_LIST"

