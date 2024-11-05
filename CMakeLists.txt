cmake_minimum_required(VERSION 3.20)
project(Test)
set_property(GLOBAL PROPERTY CTEST_TARGETS_ADDED 1)
include(CTest)
list(APPEND CMAKE_CTEST_ARGUMENTS "--output-on-failure")
include_directories(src)
set(SOURCE
tests/demo/demo.cpp
src/CircularBuffer.hpp)
add_executable(Demo ${SOURCE}) 

if(BUILD_TESTING)
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/tests)
endif()

