cmake_minimum_required(VERSION 3.16.3)

project(LinuxSystemModules)

set(CMAKE_CXX_STANDARD 14)

add_executable(LinuxSystemModules LinuxFileIO_Demo1.cpp LinuxFileIO_Demo1.h)

target_link_libraries(LinuxSystemModules libtlpi.a)