cmake_minimum_required(VERSION 3.16.3)

project(suanfa)

set(CMAKE_CXX_STANDARD 17)

add_executable(suanfaDemo suanfa.cpp)

add_executable(TestDemo MainTest.cpp CKeyEventArgs.cpp CKeyEventArgs.hpp)