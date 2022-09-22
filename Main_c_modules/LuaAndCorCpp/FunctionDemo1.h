//
// Created by XMZR on 2022/9/16.
//

#ifndef LUAANDCORCPP_FUNCTIONDEMO1_H
#define LUAANDCORCPP_FUNCTIONDEMO1_H

#include <iostream>
#include <string>

extern "C" {
#include "lua/lua.h"
#include "lua/lualib.h"
#include "lua/lauxlib.h"
};

class FunctionDemo1 {
private:
    lua_State *L = nullptr;
public:
    FunctionDemo1();

    ~FunctionDemo1();

    void Service1();

    lua_State *getLuaState();


};


#endif //LUAANDCORCPP_FUNCTIONDEMO1_H
