//
// Created by XMZR on 2022/9/16.
//

#include <cstdlib>
#include "LuaWorldDemo.h"

using namespace std;
/*

int client(int var) {
    lua_State *L = luaL_newstate();
    luaL_openlibs(L);
    int retLoad = luaL_loadfile(L, "D:\\CK\\Main_cpp_modules\\Main_c_modules\\MyLua\\MyLua2.lua");
    if (retLoad == 0) {
        printf("load file success retLoad:%d\n", retLoad);
    }
    if (retLoad || lua_pcall(L, 0, 0, 0)) {
        printf("error %s\n", lua_tostring(L, -1));
        return -1;
    }
    //调用函数,依次压入参数
    lua_getglobal(L, "add");
    lua_pushnumber(L, 10);
    lua_pushnumber(L, 20);
    //查看压入栈的元素
    for (int i = 1; i < 3; i++) {
        printf("number:%f\n", lua_tonumber(L, -i));
    }
    //lua_pcall(L,2,1,0):传入两个参数 期望得到一个返回值，0表示错误处理函数在栈中的索引值，压入结果前会弹出函数和参数
    int pcallRet = lua_pcall(L, 2, 1, 0); //lua_pcall将计算好的值压入栈顶,并返回状态值
    if (pcallRet != 0) {
        printf("error %s\n", lua_tostring(L, -1));
        return -1;
    }
    printf("pcallRet:%d\n", pcallRet);
    int val = lua_tonumber(L, -1); //在栈顶取出数据
    printf("val:%d\n", val);
    lua_pop(L, -1); //弹出栈顶
    //再次查看栈内元素，发现什么都没有，因为lua在返回函数计算值后会清空栈,只保留返回值
    for (int i = 1; i < 3; i++) {
        printf("number:%f\n", lua_tonumber(L, -i));
    }
    lua_close(L);
    return 0;
}
*/

int main() {
    //mingw 编译器下,utf-8下 代码中加入 system(“chcp 65001”) 防止中文代码
    system("chcp 65001");

    //int p = client(10);

    //LuaWorldDemo::fuckyoulua();

    //1.创建一个state
    lua_State *L = luaL_newstate();
    luaL_openlibs(L);
    int retLoad = luaL_loadfile(L, "D:\\Users\\XMZR\\CLionProjects\\Splicing-bit-fragments\\Main_c_modules\\MyLua\\MyLua3.lua");
    if (retLoad == 0) {//文件是否加载成功
        printf("load file success retLoad:%d\n", retLoad);
    }
    if (retLoad || lua_pcall(L, 0, 0, 0)) {
        printf("error %s\n", lua_tostring(L, -1));
        return -1;
    }
    //调用函数,依次压入参数
    lua_getglobal(L, "f1");
    lua_pushnumber(L, 10);
    lua_pushnumber(L, 20);
    //查看压入栈的元素
    for (int i=1;i<3;i++)
    {
        printf("number:%f\n",lua_tonumber(L, -i));
    }
    //lua_pcall(L,2,1,0):传入两个参数 期望得到一个返回值，0表示错误处理函数在栈中的索引值，压入结果前会弹出函数和参数
    int pcallRet = lua_pcall(L, 2, 1, 0); //lua_pcall将计算好的值压入栈顶,并返回状态值
    if (pcallRet != 0)
    {
        printf("error %s\n", lua_tostring(L, -1));
        return -1;
    }
    printf("pcallRet:%d\n", pcallRet);
    int val = lua_tonumber(L, -1); //在栈顶取出数据
    printf("val:%d\n", val);
    lua_pop(L, -1); //弹出栈顶
    //再次查看栈内元素，发现什么都没有，因为lua在返回函数计算值后会清空栈,只保留返回值
    for (int i=1;i<3;i++)
    {
        printf("number:%f\n",lua_tonumber(L, -i));
    }
    lua_close(L);

    return 0;
}
