cmake_minimum_required(VERSION 3.10)
project(ComplexNumbersProject)

# Установка стандарта C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Добавление исполняемого файла
add_executable(program
    src/n1.cpp
    src/n2.cpp
    src/n3.cpp
    src/n4.cpp
    main.cpp
)

# Указание пути к заголовочным файлам
target_include_directories(program PRIVATE include)