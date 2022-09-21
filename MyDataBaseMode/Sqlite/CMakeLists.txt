cmake_minimum_required(VERSION 3.16.3)

project(SqliteMode)

set(CMAKE_CXX_STANDARD 14)

add_executable(SqliteMode
        SqliteMode.cpp SqliteMode.h
        SqliteBin/sqlite3.h
        SqliteBin/sqlite3.c
        SqliteBin/sqlite3ext.h
#        SqliteBin/shell.c
        )

add_executable(DataMode
        Data.cpp
        SqliteBin/sqlite3.h
        SqliteBin/sqlite3.c
        SqliteBin/sqlite3ext.h
        #        SqliteBin/shell.c
        )

