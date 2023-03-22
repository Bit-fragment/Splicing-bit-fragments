# CMake 最低版本号要求
cmake_minimum_required(VERSION 3.16.3)
# 项目信息
project(Roam)
set(CMAKE_C_STANDARD 17)

# 添加 major tool 子目录
#add_subdirectory(fog_a)

# 指定生成目标

add_executable(Roam main.c)

# 添加链接库
target_link_libraries(Roam)