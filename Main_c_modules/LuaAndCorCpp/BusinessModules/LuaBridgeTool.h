//
// Created by XMZR on 2022/9/28.
//

#ifndef BUSINESSMODULES_LUABRIDGETOOL_H
#define BUSINESSMODULES_LUABRIDGETOOL_H
extern "C"
{
#include "lua/lua.h"
#include "lua/lauxlib.h"
#include "lua/lualib.h"
}

#include "LuaBridge/LuaBridge.h"

class LuaBridgeTool {
public:
    lua_State *lua_state = nullptr;
    const char *url = "D:\\Users\\XMZR\\CLionProjects\\Splicing-bit-fragments\\Main_c_modules\\LuaAndCorCpp\\lua_src\\LuaBirdgeDemo1Test1.lua";

    LuaBridgeTool() {
        
        this->lua_state = luaL_newstate();
    }

    ~LuaBridgeTool() {
        if (lua_state) {
            lua_close(this->lua_state);
        }
    }

};

class HotServices {
public:
    HotServices() {
        HotServices_string1 = "C++ test string";
    }

    ~HotServices() = default;

    //test方法
    void test(int a, int b) {
        printf("C++ HotServices类中的test()方法被调用 %d + %d = %d\n", a, b, a + b);
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
        lua_pushstring(L, "Value1");
        //返回参数2
        lua_pushstring(L, "Value2");
        //返回参数个数
        return 2;
    }

    std::string HotServices_string1;
    std::string m_name;
    static int m_static_data;
};

//test_lua静态变量定义（静态变量在类内只是声明）
int HotServices::m_static_data;

//HotServices子类
class HotServices_child : public HotServices {
public:
    explicit HotServices_child(std::string test) : m_test_child_string(std::move(test)) {
        printf("调用 HotServices_child 构造函数\n");
    }

    ~HotServices_child() = default;

    std::string m_test_child_string;
};

#endif //BUSINESSMODULES_LUABRIDGETOOL_H
