# Задание 3. Выведите количество файлов в указанном каталоге, включая
# подкаталоги. Если каталог не указан, то по умолчанию выбран текущий.

#!/bin/bash

if [ -z "$1" ];
then
    directory="."
else
    directory="$1"
fi

file_counter=$(find "$directory" -type f | wc -l)

echo "The number of files in the directory '$directory' (including subdirectories): $file_counter"
