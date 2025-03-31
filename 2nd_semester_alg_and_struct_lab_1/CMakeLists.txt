
# Минимальная версия CMake
cmake_minimum_required(VERSION 3.10)

# Название проекта
project(ComplexNumbersProject)

# Установка стандарта C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Добавляем исполняемый файл
add_executable(program main.cpp src/n3.cpp)

# Указываем путь к заголовочным файлам
target_include_directories(program PRIVATE include)