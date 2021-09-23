# CMakeList.txt: проект CMake для modul_27.3; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

# Добавьте источник в исполняемый файл этого проекта.
add_executable (modul273 "main.cpp" "director.h" "director.cpp"
									"manager.h" "manager.cpp"
									"worker.h" "worker.cpp"
									"group.h" "group.cpp")

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
