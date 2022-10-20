cmake_minimum_required(VERSION 3.16.3)

project(UnixNetworkCode)

set(CMAKE_CXX_STANDARD 14)

#需要的代码 http://csapp.cs.cmu.edu/public/code.html
add_executable(demo1 demo1.cpp demo1.h lib/config.h lib/unp.h)

target_link_libraries(demo1 libunp.a)
