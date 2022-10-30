cmake_minimum_required(VERSION 3.5)

project(RemoteController LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Core Quick REQUIRED)

if(ANDROID)
    add_library(RemoteController SHARED
      main.cpp
      qml.qrc
    )
else()
    add_executable(RemoteController
      main.cpp
      qml.qrc
    )
endif()

target_compile_definitions(RemoteController
  PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(RemoteController
  PRIVATE Qt5::Core Qt5::Quick)
