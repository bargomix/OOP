cmake_minimum_required(VERSION 3.14 FATAL_ERROR)
project(mylibrary VERSION 0.0.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(mylib STATIC my_lib.h my_lib.cpp)
