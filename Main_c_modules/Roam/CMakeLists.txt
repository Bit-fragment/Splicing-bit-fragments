# CMake 最低版本号要求
cmake_minimum_required(VERSION 3.16.3)
# 项目信息
project(RoamingEingang)
#set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 17)
# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_SRCS 变量
aux_source_directory(. DIR_SRCS)
# 添加 major tool 子目录
add_subdirectory(fog_a)
# 指定生成目标
#add_executable(RoamingEingang main.c)
add_executable(RoamingEingang ${DIR_SRCS})

# 添加链接库
target_link_libraries(RoamingEingang fog_a)