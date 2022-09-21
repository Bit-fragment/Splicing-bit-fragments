//
// Created by XMZR on 2022/9/15.
//
#include "lua/lua.h"
#include "lua/lualib.h"
#include "lua/lauxlib.h"
#include <stdlib.h>

int main() {
    system("chcp 65001");
    lua_State *L = luaL_newstate();
    luaL_openlibs(L);
    int retLoad = luaL_loadfile(L, "D:\\Users\\XMZR\\CLionProjects\\Splicing-bit-fragments\\Main_c_modules\\MyLua\\MyLua1.lua");
    if (retLoad == 0)
    {
        printf("load file success retLoad:%d\n", retLoad);
    }
    if (retLoad || lua_pcall(L, 0, 0, 0))
    {
        printf("error %s\n", lua_tostring(L, -1));
        return -1;
    }

    lua_getglobal(L, "name"); //lua获取全局变量name的值并且返回到栈顶
    lua_getglobal(L, "age");  //lua获取全局变量age的值并且返回到栈顶,这个时候length对应的值将代替width的值成为新栈顶
    //注意读取顺序
    int age = lua_tointeger(L, -1); //栈顶
    const char *name = lua_tostring(L, -2);//次栈顶
    printf("name = %s\n", name);
    printf("age = %d\n", age);

    lua_close(L);
    return 0;
}