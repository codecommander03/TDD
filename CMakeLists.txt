cmake_minimum_required(VERSION 3.14)
project(TDD CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()
include_directories(include)

# Auto-discover all test files under tests/
file(GLOB_RECURSE TEST_SOURCES tests/*.cpp)
file(GLOB_RECURSE SRC_SOURCES src/*.cpp)

add_executable(run_tests ${TEST_SOURCES} ${SRC_SOURCES})
target_link_libraries(run_tests GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(run_tests)