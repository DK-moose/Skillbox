cmake_minimum_required (VERSION 3.8)

project ("modul_33.1")

add_executable (modul_33.1 "main.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET modul_33.1 PROPERTY CXX_STANDARD 20)
endif()