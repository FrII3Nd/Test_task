cmake_minimum_required(VERSION 3.20)
project(Test)
include_directories(src)
set(SOURCE
tests/demo/demo.cpp
src/CircularBuffer.hpp)
add_executable(Demo ${SOURCE}) 
option(BUILD_TESTING "Enable testing" on)
if(BUILD_TESTING)
    enable_testing() 
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/tests)
endif()

