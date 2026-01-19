cmake_minimum_required(VERSION 3.14 FATAL_ERROR)
project(mylib_proj VERSION 0.0.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(BUILD_TESTS_FOR_LIB "Build tests for mylib library" ON)#добвляем option если ON то включаем тесты если OFF то мы не переходим в папку тесты


add_subdirectory(my_lib)

add_executable(exec_trg s03.cpp)
target_link_libraries(exec_trg PUBLIC mylib)
target_include_directories(exec_trg PRIVATE ${CMAKE_SOURCE_DIR}/my_lib)


if(BUILD_TESTS_FOR_LIB)
  enable_testing()
  add_subdirectory(tests)
endif()



option(ENABLE_COVERAGE "Enable coverage flags" ON)

if(ENABLE_COVERAGE)
  message(STATUS "Coverage enabled")
  # Для корректного покрытия лучше без оптимизаций
  add_compile_options(-O0 -g --coverage)
  add_link_options(--coverage)
endif()
