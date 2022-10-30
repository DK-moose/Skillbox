cmake_minimum_required(VERSION 3.5)

project(Calculator LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

if(ANDROID)
  add_library(Calculator SHARED
    main.cpp
    calculator.cpp
    calculator.h
    calculator.ui
  )
else()
  add_executable(Calculator
    main.cpp
    calculator.cpp
    calculator.h
    calculator.ui
  )
endif()

target_link_libraries(Calculator PRIVATE Qt5::Widgets)
