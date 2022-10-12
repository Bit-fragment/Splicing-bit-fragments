cmake_minimum_required(VERSION 3.16.3)

project(LinuxSystemModules)

set(CMAKE_CXX_STANDARD 14)

add_executable(LinuxFileIO_Demo1 LinuxFileIO_Demo1.cpp LinuxFileIO_Demo1.h)
add_executable(LinuxSocket_Demo1 LinuxSocket_Demo1.cpp LinuxSocket_Demo1.h)


#target_link_libraries(LinuxFileIO_Demo1 libtlpi.a)
target_link_libraries(LinuxFileIO_Demo1)