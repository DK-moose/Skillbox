# CMakeList.txt: проект CMake для modul_26.3; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

# Добавьте источник в исполняемый файл этого проекта.
add_executable (modul263 "main.cpp" "point.h" "point.cpp"
				    "screen.h" "screen.cpp"
				    "window.h" "window.cpp")

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
