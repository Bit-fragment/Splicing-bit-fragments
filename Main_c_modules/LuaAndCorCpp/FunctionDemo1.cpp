//
// Created by XMZR on 2022/9/16.
//

#include "FunctionDemo1.h"
#include "FunctionDemo2.h"

void see(lua_State *L, int max_size, std::string messg) {
    std::cout << "======================== " << messg << std::endl;
    for (int i = 1; i < max_size; i++) {
        printf("[%d]Value:%f\n", -i, lua_tonumber(L, -i));
    }
    std::cout << "======================== " << messg << std::endl;
}

int sayHello(lua_State *L) {
    see(L, 3, "sayHello1");
    std::string name = luaL_checkstring(L, -1);
    see(L, 3, "sayHello2");

//    FunctionDemo2 f2;
//    int var = f2.Dao1(name.length());

    lua_pushnumber(L, name.length());//将值放入栈顶
    see(L, 3, "sayHello3");
    return 1; //result count
}

int main() {
    system("chcp 65001");
    FunctionDemo1 functionDemo1;
    see(functionDemo1.getLuaState(), 3, "main1");
    functionDemo1.Service1();
    see(functionDemo1.getLuaState(), 3, "main2");
    return 0;
}

void FunctionDemo1::Service1() {
    luaL_dofile(this->L, "D:\\Users\\XMZR\\CLionProjects\\Splicing-bit-fragments\\Main_c_modules\\MyLua\\MyLua3.lua");
}

FunctionDemo1::FunctionDemo1() {
//1.创建一个state
    this->L = luaL_newstate();
    luaL_openlibs(L);
    lua_register(L, "sayHello", sayHello);
}

FunctionDemo1::~FunctionDemo1() {
    lua_close(L);
}

lua_State *FunctionDemo1::getLuaState() {
    return this->L;
}
