cmake_minimum_required(VERSION 3.13)
project(Exercises)

# Set output folder
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

# The following folder will be included
include_directories("${PROJECT_SOURCE_DIR}")

# Version numbers
set (Exercises_VERSION_MAJOR 1)
set (Exercises_VERSION_MINOR 0)

set(SOURCE_FILES
        src/Test.cpp
        src/BasicVector.cpp
        src/BasicVector.h
        src/Conversion.cpp
        src/Conversion.h
        src/Collatz.cpp
        src/Collatz.h)

add_executable(Exercises ${SOURCE_FILES})