cmake_minimum_required(VERSION 3.20)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(GTest REQUIRED)

add_executable(
  Test
  ${CMAKE_CURRENT_SOURCE_DIR}/test_buffer.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/../src/CircularBuffer.hpp
)
target_link_libraries(
  Test
  GTest::gtest_main

)

include(GoogleTest)
gtest_discover_tests(Test)