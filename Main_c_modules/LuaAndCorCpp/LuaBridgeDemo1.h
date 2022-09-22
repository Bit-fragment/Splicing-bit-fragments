//
// Created by XMZR on 2022/9/22.
//

#ifndef LUAANDCORCPP_LUABRIDGEDEMO1_H
#define LUAANDCORCPP_LUABRIDGEDEMO1_H
extern "C"
{
#include "lua/lua.h"
#include "lua/lauxlib.h"
#include "lua/lualib.h"
}

#include "LuaBridge/LuaBridge.h"

class LuaBridgeDemo1 {

};

class test_lua {
public:
    test_lua() {
        m_test_string = "c++ test string";
    }

    ~test_lua() {
    }

//test方法
    void test(int a, int b) {
        printf("c++ test function %d+%d=%d\n", a, b, a + b);
    }

//属性set方法
    void SetName(std::string name) {
        m_name = name;
    }

//属性get方法，注意需要后面加const
    std::string GetName() const {
        return m_name;
    }

//供lua调用方法，返回多个参数方法
    int cFunc(lua_State *L) {
//返回参数1
        lua_pushstring(L, "str1");
//返回参数1
        lua_pushstring(L, "str2");
//返回参数个数
        return 2;
    }

    std::string m_test_string;
    std::string m_name;
    static int m_static_data;
};

//test_lua静态变量定义（静态变量在类内只是声明）
int test_lua::m_static_data;

//test_lua子类
class test_lua_child : public test_lua {
public:
    test_lua_child(std::string test)
            : m_test_child_string(test) {
        printf("call test_lua_child constructor\n");
    }

    ~test_lua_child() {
    }

    std::string m_test_child_string;
};


#endif //LUAANDCORCPP_LUABRIDGEDEMO1_H
