cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

project(my_lib LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(mylib STATIC my_lib.h my_lib.cpp) #добавляем статическую библиотеку (создаём) и указываем название цель, тип и файл библиотеки

# add_library(mylib SHARED my_lib.h my_lib.cpp)

#разница между shared и static при линковке, при запуске
#static вшиваем в цель(s03) библиотеку
#shared при запуске программы она знает имя библиотеки и что в ней есть, и обращается к ней когда нужно
