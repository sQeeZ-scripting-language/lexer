cmake_minimum_required(VERSION 3.0)
project(interpreter)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${PROJECT_SOURCE_DIR}/include)

set(SOURCES
    src/main.cpp
    src/interpreter.cpp
    include/interpreter.hpp
)

add_executable(interpreter ${SOURCES})