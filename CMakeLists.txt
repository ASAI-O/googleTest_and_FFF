cmake_minimum_required(VERSION 3.20)

project(MyProject LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)

#
# GoogleTest
#
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.17.0
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

#
# FFF
#
FetchContent_Declare(
    fff
    GIT_REPOSITORY https://github.com/meekrosoft/fff.git
    GIT_TAG master
)

FetchContent_MakeAvailable(fff)

#
# ライブラリ
#
add_library(
    MyLibrary
    src/main.cpp
)

target_include_directories(
    MyLibrary
    PUBLIC
    ${CMAKE_SOURCE_DIR}/src
)

#
# テスト
#
add_executable(
    MyTests
    tests/test_sample.cpp
)

target_include_directories(
    MyTests
    PRIVATE
    ${fff_SOURCE_DIR}
)

target_link_libraries(
    MyTests
    PRIVATE
    MyLibrary
    GTest::gtest
    GTest::gtest_main
)

enable_testing()

include(GoogleTest)
gtest_discover_tests(MyTests)