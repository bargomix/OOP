
cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

project(tests LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


include(FetchContent)#подключаем модуль для того что бы скачать google test

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/heads/main.zip
)#указываем куда скачать и что скачать 

FetchContent_MakeAvailable(googletest)#автоматически скачает и создаст то что мы можем использовать делается add_subdirectory

add_executable(mylib_tests test_mylib.cpp)#создаём цель

target_link_libraries(mylib_tests
    PRIVATE
        mylib
        gtest_main
)#прописываем цель, используем нашу библиотеку а так же gtest_main которая автоматически создалась, получает пути библиотек

target_include_directories(mylib_tests PRIVATE ${CMAKE_SOURCE_DIR}/my_lib)

include(GoogleTest)#подключаем тесты
gtest_discover_tests(mylib_tests)#дает возможность автоматически обнаруживать и регистрировать тесты и написать ctest
