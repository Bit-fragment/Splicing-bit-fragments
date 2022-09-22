cmake_minimum_required(VERSION 3.16.3)

# 设置VCPKG_ROOT所在的位置
#set(VCPKG_ROOT "D:\\CK\\vcpkg\\scripts\\buildsystems\\vcpkg.cmake" CACHE PATH "")
#set(CMAKE_TOOLCHAIN_FILE ${VCPKG_ROOT})

project(LuaAndCorCpp)

set(CMAKE_CXX_STANDARD 14)

#set(CMAKE_C_FLAGS)

#find_package(Lua REQUIRED)

add_executable(LuaAndCorCpp mian.c)

add_executable(LuaWorldDemo LuaWorldDemo.h LuaWorldDemo.cpp
        FunctionDemo2.h FunctionDemo2.cpp
        )

add_executable(FunctionDemo1 FunctionDemo1.cpp FunctionDemo1.h )

add_executable(LuaBridgeDemo1 LuaBridgeDemo1.cpp LuaBridgeDemo1.h)



target_link_libraries(LuaBridgeDemo1 liblua.a lua.lib)

target_link_libraries(FunctionDemo1 liblua.a lua.lib)

#target_include_directories(LuaAndCorCpp PUBLIC ${LUA_INCLUDE_DIR})

target_link_libraries(LuaAndCorCpp liblua.a lua.lib)

target_link_libraries(LuaWorldDemo liblua.a lua.lib)
