cmake_minimum_required(VERSION 3.25)
project(Akebi_GC)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Akebi_GC
        cheat.cpp
        cheat.h
        debugger.cpp
        debugger.h
        events.cpp
        events.h
        GenshinCM.cpp
        GenshinCM.h
        ILPatternScanner.cpp
        ILPatternScanner.h
        injector.cpp
        injector.h
        main.cpp
        native.cpp
        native.h
        resource.h
        util.cpp
        util.h)
