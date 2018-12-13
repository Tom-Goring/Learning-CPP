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

set(SOURCE_FILES src/MinimumBase.cpp)

add_executable(Exercises ${SOURCE_FILES})