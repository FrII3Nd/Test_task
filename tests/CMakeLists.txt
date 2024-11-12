cmake_minimum_required(VERSION 3.20)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
find_package(CppUTest CONFIG REQUIRED)
add_executable(
        tests
        ${CMAKE_CURRENT_SOURCE_DIR}/test_buffer.cpp
)
target_link_libraries(tests cpputest::cpputest)
