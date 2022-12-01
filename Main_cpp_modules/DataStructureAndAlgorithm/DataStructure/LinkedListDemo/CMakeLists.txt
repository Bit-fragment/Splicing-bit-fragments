cmake_minimum_required(VERSION 3.16.3)

project(DataStructureAndAlgorithm)

set(CMAKE_CXX_STANDARD 14)

#链表
add_executable(MainDemo MainDemo.cpp LinkedListMy.hpp LinkedListMy.cpp ../Test/TestMain.cpp)

#add_executable(MainDemo MainDemo.cpp)