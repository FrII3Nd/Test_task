cmake_minimum_required(VERSION 3.20)
project(Test)
include_directories(lib)
set(SOURCE
src/main.cpp
lib/CircularBuffer.hpp)
add_executable(Test ${SOURCE})

