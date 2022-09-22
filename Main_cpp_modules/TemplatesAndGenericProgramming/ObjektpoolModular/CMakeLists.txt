cmake_minimum_required(VERSION 3.16.3)

project(DiyObjektPool)

set(CMAKE_CXX_STANDARD 14)

#职责链模式
add_executable(DiyObjektPool DiyObjektPool.cpp DiyObjektPool.h DiyReferenceCounter.cpp)