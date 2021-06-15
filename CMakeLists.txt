cmake_minimum_required(VERSION 3.14)

project(EwolucjaAgresji)

set(LIBRARY_OUTPUT_PATH build/)
set(BINARY_OUTPUT_PATH build/)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-g3 -pthread -fconcepts -Wall -pedantic")
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}")

# MAIN PROJECT 
set(PROJECT_SOURCES)
include_directories(${PROJECT_SOURCE_DIR}/Include)
add_subdirectory(${PROJECT_SOURCE_DIR}/Source)
add_executable(EwolucjaAgresji "main.cpp" ${PROJECT_SOURCES})
add_definitions("-DPROJECT_BUILD_PATH=\"${PROJECT_BINARY_DIR}\"")

#UT
add_executable(ewolucja_agresji_ut "test.cpp" ${PROJECT_SOURCES})