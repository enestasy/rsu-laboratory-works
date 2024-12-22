# Задание 1. Выведите таблицу степеней (от 0 до 6) натуральных чисел в
# диапазоне от 1 до 9 в виде таблицы, где строки – степени одного числа.

#!/bin/bash

degree() {
    local degree_value=$1
    local num_value=$2
    curr_value=1

    if [ "$degree_value" -eq 0 ];
    then
        echo -n "1 "
    else
        for ((d = 1; d <= degree_value; d++));
        do
            curr_value=$((curr_value * num_value))
        done
        echo -n "$curr_value "
    fi
}

for ((a = 1; a <= 9; a++));
do
    echo -n "number $a: "
    for ((i = 0; i <= 6; i++));
    do
        degree "$i" "$a"
    done
    echo
done
