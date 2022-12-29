cmake_minimum_required(VERSION 3.16.3)

project(MMORPGserver)

set(CMAKE_CXX_STANDARD 14)

# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_SRCS 变量
aux_source_directory(. DIR_SRCS)
# 添加 major tool 子目录
add_subdirectory(server)

add_executable(MMORPGserver ServerStart.cpp)

target_link_libraries(MMORPGserver server)
