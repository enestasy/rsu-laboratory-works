# Задание 12. Напишите аналог команды killall, которая принимает имя процессов, которые нужно завершить.

#!/bin/bash

SIGNAL=15

while [[ $# -gt 0 ]];
do
    case "$1" in
        -s)
            if [[ -n $2 ]];
            then
                SIGNAL="$2"
                shift 2
            else
                echo "Error! No signal specified" >> "$ERROR_LOG"
                exit 1
            fi
            ;;
        -h)
            echo "Usage: $0 [-s signal_number] process_name"
            echo "  -s          Specify signal number to send"
            echo "  process_name Process to kill"
            exit 0
            ;;
        *)
            PROCESS_NAME="$1"
            shift
            ;;
    esac
done

if [[ -z $PROCESS_NAME ]];
then
    echo "Error! No process name specified" >> "$ERROR_LOG"
    exit 1
fi

pkill -$SIGNAL "$PROCESS_NAME"
