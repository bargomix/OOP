cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

project(s03_proj LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON) #если не включать то если cmake не получит 17 версию то опустится ниже, сейчас ошибка

add_subdirectory(my_lib) # добаляем директорию my_lib, ищем там cmake и запускаем его, для возможности линковка


add_executable(s03 s03.cpp) #определяем конечную цель, исполняемый файл
target_link_libraries(s03 PRIVATE mylib) #связываем библиотеку с целью и делаем так что бы библиотека компилировалась раньше 
target_include_directories(s03 PRIVATE ${CMAKE_SOURCE_DIR}/my_lib) #подключаем директорию с нашей библиотекой (можно не прописывать полный путь в s03 можно указать my_lib.h)

enable_testing()#включаем тесты
add_subdirectory(tests)
