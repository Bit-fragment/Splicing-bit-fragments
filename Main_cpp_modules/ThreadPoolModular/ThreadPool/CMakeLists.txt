cmake_minimum_required(VERSION 3.16.3)

project(ThreadPool)

set(CMAKE_CXX_STANDARD 14)

#线程池 https://github.com/progschj/ThreadPool
add_executable(ThreadPool example.cpp ThreadPool.h)