# CMake 最低版本号要求
cmake_minimum_required(VERSION 3.16.3)
# 项目信息
project(Test)

set(CMAKE_CXX_STANDARD 17)
# 指定生成目标
add_executable(TestMain TestMain.cpp)
