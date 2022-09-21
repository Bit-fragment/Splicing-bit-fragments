//
// Created by XMZR on 2022/8/31.
//
#include <stdio.h>
#include <malloc.h>
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
#define Number 10
#define Mychar "How much time do you have?\n"

int *getList(int size) {
    int *pi = malloc(size * sizeof(int));
    if (NULL != pi) {
        for (int i = 0; i < size; i++) {
            pi[i] = i;
        }
        return pi;
    }
    return 0;
}

int main() {
    /*printf("%d\n", Number);
    printf(Mychar);

    printf("Hello c world!\n");
    int size = 10;
    int *pi = getList(size);
    for (int i = 0; i < size; i++) {
        printf("%d ", pi[i]);
    }
    free(pi);*/


    lua_State *L = luaL_newstate();
    luaL_openlibs(L);
    int retLoad = luaL_loadfile(L, "MyLua/MyLua1.lua");
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