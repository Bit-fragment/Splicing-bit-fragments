//
// Created by XMZR on 2022/9/28.
//

#ifndef BUSINESSMODULES_LUATOOL_H
#define BUSINESSMODULES_LUATOOL_H
extern "C"
{
#include "lua/lua.h"
#include "lua/lauxlib.h"
#include "lua/lualib.h"
}

#include "LuaBridge/LuaBridge.h"

class InterfaceProvider {

};

template <class T>
class LuaObject {
private:
    lua_State *lua_state = nullptr;
    const char *url = "D:\\Users\\XMZR\\CLionProjects\\Splicing-bit-fragments\\Main_c_modules\\LuaAndCorCpp\\lua_src\\LuaBirdgeDemo1Test1.lua";
public:
    LuaObject(T t){
        this->lua_state = luaL_newstate();
        //加载Lua基本库
        luaL_openlibs(lua_state);
    }
    ~LuaObject(){
        if(lua_state){
            lua_close(this->lua_state);
        }
    }
};

class LuaMethodCaller {

};

class LuaTool {

};


#endif //BUSINESSMODULES_LUATOOL_H
