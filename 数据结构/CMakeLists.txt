cmake_minimum_required(VERSION 3.10)
project(DataStruct LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(test_all tests/test_all.cpp)
target_include_directories(test_all PRIVATE include)
