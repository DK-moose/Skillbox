cmake_minimum_required(VERSION 3.5)

project(MyButton LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Widgets Multimedia MultimediaWidgets REQUIRED)

if(ANDROID)
  add_library(MyButton SHARED
    main.cpp
    imagebutton.cpp
    imagebutton.h
  )
else()
  add_executable(MyButton
    main.cpp
    imagebutton.cpp
    imagebutton.h
  )
endif()

target_link_libraries(MyButton PRIVATE Qt5::Widgets Qt5::Multimedia Qt5::MultimediaWidgets)
