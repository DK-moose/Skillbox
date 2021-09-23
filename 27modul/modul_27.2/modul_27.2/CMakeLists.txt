# CMakeList.txt: проект CMake для modul_27.2; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

# Добавьте источник в исполняемый файл этого проекта.
add_executable (modul272 "main.cpp" "point.h" "point.cpp"
                                    "figure.h" "figure.cpp"
                                    "circle.h" "circle.cpp"
                                    "square.h" "square.cpp"
                                    "triangle.h" "triangle.cpp"
                                    "rectangle.h" "rectangle.cpp")

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
