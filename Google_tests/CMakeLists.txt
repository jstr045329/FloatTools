cmake_minimum_required(VERSION 3.19)
project(FloatTools C CXX)
set(CMAKE_CXX_STANDARD 17)
find_package(GTest REQUIRED)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
add_executable(
        TestFloatTools
        ../FloatTools.cpp
        ./testFloatTools.cpp
        testMain.cpp)
target_link_libraries(TestFloatTools gtest gtest_main pthread)
