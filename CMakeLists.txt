cmake_minimum_required(VERSION 3.20)
project(Test)
include_directories(src)
set(SOURCE
tests/demo/demo.cpp
src/CircularBuffer.hpp)
add_executable(Test ${SOURCE})
if(BUILD_TESTING)
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/tests)
endif()

