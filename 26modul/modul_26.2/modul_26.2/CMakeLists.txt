﻿# CMakeList.txt: проект CMake для modul_26.2; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

# Добавьте источник в исполняемый файл этого проекта.
add_executable (modul262 "main.cpp" "record.h" "record.cpp"
				    "phone.h" "phone.cpp")

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
