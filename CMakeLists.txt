# Specify the minimum version for CMake

cmake_minimum_required(VERSION 2.8)
# Project's name

project(hello)

enable_testing()

# Set the output folder where your program will be created
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

set(MAIN_SRC "${PROJECT_SOURCE_DIR}/src/main")
set(SPACEMINER_SRC "${PROJECT_SOURCE_DIR}/src/spaceminer")


# The following folder will be included
include_directories("${SPACEMINER_SRC}")

#define a variable SOURCES
file(GLOB_RECURSE SPACEMINER_SOURCES "${SPACEMINER_SRC}/*.cpp" )

file(GLOB_RECURSE MAIN_SOURCES "${MAIN_SRC}/*.cpp" )

# maybe use find_library at some point when linking becomes fun

add_executable(hello ${MAIN_SOURCES} ${SPACEMINER_SOURCES})

# Tests
set(TEST_SRC "${PROJECT_SOURCE_DIR}/src/test")
file(GLOB_RECURSE TEST_SOURCES "${TEST_SRC}/*.t.cpp" )
add_executable(Test ${TEST_SOURCES} ${SPACEMINER_SOURCES} )
add_test(spaceminerTest Test)
