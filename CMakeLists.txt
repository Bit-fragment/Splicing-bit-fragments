cmake_minimum_required(VERSION 3.16.3)
project(MyCppWorld)

#link_directories("D:/Ruanjian0/MinGW64/mingw64/x86_64-w64-mingw32/include/myocci")

set(CMAKE_CXX_STANDARD 14)
#include_directories('D:/Ruanjian0/MinGW64/mingw64/x86_64-w64-mingw32/include/myocci')
#include_directories('D:/Ruanjian0/Oracle19c/Oracle_19_db_home/oci/include')
#add_library('D:/Ruanjian0/Oracle19c/Oracle_19_db_home/oci/lib')
#add_library( Main_cpp_modules SHARED ${lib_src})

add_executable(MyCppWorld_MyServer Test_code_module/Server/ServerModel.cpp
        Test_code_module/Server/Service/ServiceObject.cpp
        Test_code_module/Server/Service/ServiceObject.h)

add_executable(MyTextMode_main1 Test_code_module/src/main1.cpp Test_code_module/src/main1.h
        Test_code_module/MyException.cpp Test_code_module/MyException.h)

add_executable(MyTextMode_main2 Test_code_module/src/main2.cpp
        Test_code_module/mode1/FileUtil.cpp Test_code_module/mode1/FileUtil.h Test_code_module/mode1/Object.cpp Test_code_module/mode1/Object.h
        Test_code_module/MyList.cpp Test_code_module/MyList.h
        Test_code_module/MyException.cpp Test_code_module/MyException.h
        Test_code_module/src/main2.h Test_code_module/MacroDefinition/MyMacro_1.h)

#target_link_libraries(Main_cpp_modules mycooi/occiCommon.h)
