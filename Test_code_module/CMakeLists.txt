cmake_minimum_required(VERSION 3.16.3)

project(Test_code_module)

set(CMAKE_CXX_STANDARD 14)

add_executable(MyExceptionMain MyExceptionMain.cpp
        MyException.cpp MyException.h)