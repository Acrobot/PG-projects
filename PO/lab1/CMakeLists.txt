cmake_minimum_required(VERSION 3.3)
project(lab1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp number_value.h number.h number.cpp complex.cpp complex.h)
add_executable(lab1 ${SOURCE_FILES})