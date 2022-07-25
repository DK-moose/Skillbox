cmake_minimum_required (VERSION 3.8)

project ("modul_32.1")

set(CMAKE_CXX_STANDARD 14)

set(JSON_BuildTests OFF CACHE INTERNAL "")

add_subdirectory(nlohmann_json)

add_executable (modul_32.1 "main.cpp")

target_link_libraries(modul_32.1 PRIVATE nlohmann_json::nlohmann_json)

