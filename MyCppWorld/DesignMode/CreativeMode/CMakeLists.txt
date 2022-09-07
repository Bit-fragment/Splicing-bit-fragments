cmake_minimum_required(VERSION 3.22)

#创建型设计模式
project(CreativeMode)

set(CMAKE_CXX_STANDARD 14)

add_executable(SingleColumnMy SingleColumnMy.cpp SingleColumnMy.h)

add_executable(FactoryMode FactoryMode.cpp FactoryMode.h)

add_executable(BuilderMode BuilderMode.cpp BuilderMode.h)

add_executable(PrototypeMode PrototypeMode.cpp PrototypeMode.h)