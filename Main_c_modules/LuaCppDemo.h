//
// Created by XMZR on 2022/9/15.
//

#ifndef MYCWORKD_LUACPPDEMO_H
#define MYCWORKD_LUACPPDEMO_H
extern "C" {
#include "lua/lua.h"
#include "lua/lualib.h"
#include "lua/lauxlib.h"
};

//int Add(lua_State *L) {
//    lua_Integer a = lua_tointeger(L, 1);
//    lua_Integer b = lua_tointeger(L, 2);
//    lua_pushinteger(L, a + b);
//    return 1;
//}
//
//int Sub(lua_State *L) {
//    lua_Integer a = lua_tointeger(L, 1);
//    lua_Integer b = lua_tointeger(L, 2);
//    lua_pushinteger(L, a - b);
//    return 1;
//}
//
//static luaL_Reg CustomLib[] =
//        {
//                {"Add", Add},
//                {"Sub", Sub},
//                {NULL, NULL}
//        };
//
//// Custom必须和动态库名字保持一致,必须导出C风格
//extern "C" int luaopen_Custom(lua_State *L) {
//    luaL_newlib(L, CustomLib);
//    return 1;
//}

class LuaCppDemo {

};


#endif //MYCWORKD_LUACPPDEMO_H
