# tests/CMakeLists.txt

project(book_tests LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# GoogleTest через FetchContent
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
FetchContent_MakeAvailable(googletest)

# создаём исполняемый файл для тестов
add_executable(tests test_mylib.cpp)

# заголовки библиотеки
target_include_directories(tests PRIVATE ${CMAKE_SOURCE_DIR}/my_lib)

# линкуем нашу библиотеку и gtest_main
target_link_libraries(tests PRIVATE mylib gtest_main)

# подключаем gtest и регистрируем тесты
include(GoogleTest)
gtest_discover_tests(tests)
