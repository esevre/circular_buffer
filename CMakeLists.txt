cmake_minimum_required(VERSION 3.8)
project(circular_buffer)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main.cpp circle_buffer.hpp circle_buffer_array.hpp test_circle_buffer.hpp circle_buffer_abstract.hpp)
add_executable(circular_buffer ${SOURCE_FILES})