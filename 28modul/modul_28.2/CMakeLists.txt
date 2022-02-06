# CMakeList.txt: проект CMake для modul_28.2; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

project ("modul_28.2")

# Добавьте источник в исполняемый файл этого проекта.
add_executable (modul_28.2 "main.cpp" "train.h" "train.cpp")

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
