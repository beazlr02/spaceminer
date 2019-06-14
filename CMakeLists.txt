# Specify the minimum version for CMake

cmake_minimum_required(VERSION 2.8)

# Project's name

project(hello)
# Set the output folder where your program will be created
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

set(MAIN_SRC "${PROJECT_SOURCE_DIR}/src/main")

# The following folder will be included
include_directories("${MAIN_SRC}")

#define a variable SOURCES
file(GLOB_RECURSE SOURCES "${MAIN_SRC}/*.cpp")

# maybe use find_library at some point when linking becomes fun

add_executable(hello ${SOURCES})
