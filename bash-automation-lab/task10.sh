# Задание 10. На вход подаётся каталог и файл настроек, в который дописывается информация, получаемая от пользователя в интерактивном режиме.

#!/bin/bash


ERROR_LOG="error_log_task10.txt"
CONFIG_FILE=".install-config"
TARGET_DIR=""
USER_NAME=$(whoami)
GROUP_NAME=$(id -gn)


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
        -o)
            if [[ -n $2 ]];
            then
                CONFIG_FILE="$2"
                shift 2
            else
                echo "Error! No config file specified" >> "$ERROR_LOG"
                exit 1
            fi
            ;;
        -p)
            if [[ -n $2 ]];
            then
                TARGET_DIR="$2"
                shift 2
            fi
            ;;
        -m)
            if [[ -n $2 ]];
            then
                MODE="$2"
                shift 2
            fi
            ;;
        -u)
            if [[ -n $2 ]];
            then
                USER_NAME="$2"
                shift 2
            fi
            ;;
        -g)
            if [[ -n $2 ]];
            then
                GROUP_NAME="$2"
                shift 2
            fi
            ;;
        -h)
            echo "Usage: $0 [-e error_log_file] [-o config_file] [-p path] [-m mode] [-u user] [-g group] directory"
            echo "  -e          Specify a file to log errors"
            echo "  -o          Specify a configuration file"
            echo "  -p          Set the default path"
            echo "  -m          Set the default file mode"
            echo "  -u          Set the default user"
            echo "  -g          Set the default group"
            exit 0
            ;;
        *)
            echo "Unknown argument: $1" >> "$ERROR_LOG"
            exit 1
            ;;
    esac
done

for file in "$TARGET_DIR"/*;
do
    echo "Enter final path for file '$file' (default: $HOME): "
    read -r path
    path=${path:-$HOME}
    
    echo "Enter file mode (default: 0644): "
    read -r mode
    mode=${mode:-0644}
    
    echo "Enter user name (default: $USER_NAME): "
    read -r user
    user=${user:-$USER_NAME}
    
    echo "Enter group name (default: $GROUP_NAME): "
    read -r group
    group=${group:-$GROUP_NAME}
    
    echo "$file : $mode : $user : $group" >> "$CONFIG_FILE"
done
