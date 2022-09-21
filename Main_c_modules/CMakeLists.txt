cmake_minimum_required(VERSION 3.16.3)

# 设置VCPKG_ROOT所在的位置
set(VCPKG_ROOT "${CMAKE_SOURCE_DIR}/../vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE PATH "")
set(CMAKE_TOOLCHAIN_FILE ${VCPKG_ROOT})

project(MyCWorkd)

set(CMAKE_CXX_STANDARD 14)


#find_package(lua CONFIG REQUIRED)

find_package(Lua REQUIRED)


include_directories(MyCWorld/LuaBin/include)
include_directories(MyCWorld/LuaBin/lib)

#include_directories(D:/CK/Code/lua-5.4.4/dist/include)

add_executable(MyCWorkd myc.c myc.h)

add_executable(LuaCppDemo LuaCppDemo.h LuaCppDemo.cpp)

add_executable(MyAlgorithm_day1 MyAlgorithm_day1.c)

# 链接OpenCV库
#target_link_libraries(MyAlgorithm_day1 Main_c_modules/LuaBin/include/liblua.a)

target_include_directories(MyAlgorithm_day1 PRIVATE ${LUA_INCLUDE_DIR})

target_link_libraries(MyAlgorithm_day1 PRIVATE ${LUA_LIBRARIES})


#add_executable(mylua LuaBin/lapi.c LuaBin/lapi.h LuaBin/lauxlib.c LuaBin/lauxlib.h LuaBin/lbaselib.c LuaBin/lcode.c LuaBin/lcode.h LuaBin/lcorolib.c LuaBin/lctype.c LuaBin/lctype.h LuaBin/ldblib.c LuaBin/ldebug.c LuaBin/ldebug.h LuaBin/ldo.c LuaBin/ldo.h LuaBin/ldump.c LuaBin/lfunc.c LuaBin/lfunc.h LuaBin/lgc.c LuaBin/lgc.h LuaBin/linit.c LuaBin/liolib.c LuaBin/ljumptab.h LuaBin/llex.c LuaBin/llex.h LuaBin/llimits.h LuaBin/lmathlib.c LuaBin/lmem.c LuaBin/lmem.h LuaBin/loadlib.c LuaBin/lobject.c LuaBin/lobject.h LuaBin/lopcodes.c LuaBin/lopcodes.h LuaBin/lopnames.h LuaBin/loslib.c LuaBin/lparser.c LuaBin/lparser.h LuaBin/lprefix.h LuaBin/lstate.c LuaBin/lstate.h LuaBin/lstring.c LuaBin/lstring.h LuaBin/lstrlib.c LuaBin/ltable.c LuaBin/ltable.h LuaBin/ltablib.c LuaBin/ltm.c LuaBin/ltm.h LuaBin/lua.c LuaBin/lua.h LuaBin/lua.hpp LuaBin/luac.c LuaBin/luaconf.h LuaBin/lualib.h LuaBin/lundump.c LuaBin/lundump.h LuaBin/lutf8lib.c LuaBin/lvm.c LuaBin/lvm.h LuaBin/lzio.c LuaBin/lzio.h)