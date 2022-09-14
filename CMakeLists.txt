cmake_minimum_required(VERSION 3.16.3)
project(MyCppWorld)

#link_directories("D:/Ruanjian0/MinGW64/mingw64/x86_64-w64-mingw32/include/myocci")

set(CMAKE_CXX_STANDARD 14)
#include_directories('D:/Ruanjian0/MinGW64/mingw64/x86_64-w64-mingw32/include/myocci')
#include_directories('D:/Ruanjian0/Oracle19c/Oracle_19_db_home/oci/include')
#add_library('D:/Ruanjian0/Oracle19c/Oracle_19_db_home/oci/lib')
#add_library( MyCppWorld SHARED ${lib_src})

add_executable(MyCppWorld_MyServer MyTextMode/Server/ServerModel.cpp
        MyTextMode/Server/Service/ServiceObject.cpp
        MyTextMode/Server/Service/ServiceObject.h)

add_executable(MyCppWorld3 src/main1.cpp src/main1.h
        MyTextMode/MyException.cpp MyTextMode/MyException.h )

add_executable(MyCppWorld src/main2.cpp
        mode1/FileUtil.cpp mode1/FileUtil.h mode1/Object.cpp mode1/Object.h
        MyTextMode/MyList.cpp MyTextMode/MyList.h
        MyTextMode/MyException.cpp MyTextMode/MyException.h
        src/main2.h MyTextMode/MacroDefinition/MyMacro_1.h)

#target_link_libraries(MyCppWorld mycooi/occiCommon.h)
