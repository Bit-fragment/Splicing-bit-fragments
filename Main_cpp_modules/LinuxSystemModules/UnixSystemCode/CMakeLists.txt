cmake_minimum_required(VERSION 3.16.3)

project(LinuxMain)

set(CMAKE_CXX_STANDARD 14)

add_executable(LinuxMain main.cpp LinuxSystemCode.h)

add_executable(TCP_Servicer_demo1 TCP_Servicer_demo1.cpp)

add_executable(TCP_Client_demo1 TCP_Client_demo1.cpp)