cmake_minimum_required(VERSION 3.16.3)

project(BusinessModules)

set(CMAKE_CXX_STANDARD 14)

add_executable(BusinessModules
        LuaBridgeTool.cpp LuaBridgeTool.h
        LuaTool.cpp LuaTool.h

        )

target_link_libraries(BusinessModules liblua.a lua.lib)
