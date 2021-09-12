# CMakeList.txt: проект CMake для modul_25.2; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

# Добавьте источник в исполняемый файл этого проекта.
add_executable (modul252 "main.cpp" "cpu.h" "cpu.cpp"
                         	    "ram.h" "ram.cpp"
                         	    "disk.h" "disk.cpp"
                         	    "gpu.h" "gpu.cpp"
                         	    "kbd.h" "kbd.cpp")

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
