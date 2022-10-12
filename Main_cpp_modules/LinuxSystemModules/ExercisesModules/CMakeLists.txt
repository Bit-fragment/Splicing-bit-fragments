cmake_minimum_required(VERSION 3.16.3)

project(LinuxSystemModules)

set(CMAKE_CXX_STANDARD 14)

#需要的代码 http://csapp.cs.cmu.edu/public/code.html
add_executable(Exercises Exercises.c csapp.h csapp.c)