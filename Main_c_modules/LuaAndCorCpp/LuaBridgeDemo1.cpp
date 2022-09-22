//
// Created by XMZR on 2022/9/22.
//

#include "LuaBridgeDemo1.h"

template<typename R, typename T1, typename T2>
R call(lua_State* lua_state,const char* name, T1 arg1, T2 arg2)
{
//读取方法名
    lua_getglobal(lua_state, name);
//判断是不是方法
    if (lua_isfunction(lua_state, -1))
    {
//压入参数
        luabridge::Stack<T1>::push(lua_state, arg1);
        luabridge::Stack<T2>::push(lua_state, arg2);
//执行函数（参数为lua对象、参数个数，返回值个数，出错返回）
        lua_pcall(lua_state, 2, 1, 0);
    }
//获取返回值
    return luabridge::Stack<R>::get(lua_state, -1);
}

int main() {
    //初始化Lua （最后记得调用lua_close(lua_state)释放）
    lua_State* lua_state = luaL_newstate();
    //加载Lua基本库
    luaL_openlibs(lua_state);
    luabridge::getGlobalNamespace(lua_state)
            .beginNamespace("test")
            .beginClass<test_lua>("test_lua")
            .addConstructor<void (*) (void)> ()//无参构造函数的注册
            .addData("test_str",&test_lua::m_test_string)//注册变量到lua
            .addStaticData("static_data", &test_lua::m_static_data)//注册静态变量到lua
            .addFunction("test", &test_lua::test)//注册test、方法到lua（addStaticFunction静态函数注册也类似）
            .addProperty("name",&test_lua::GetName,&test_lua::SetName)//属性方法的注册（addStaticProperty静态属性方法也类似）
            .addCFunction("cFunc",&test_lua::cFunc)//注册返回多个参数给lua的方法
            .endClass()
            .deriveClass<test_lua_child, test_lua> ("test_lua_child")//子类的注册
            .addConstructor<void (*) (std::string)> ()//有参构造函数的注册
            .addData("test_child_string", &test_lua_child::m_test_child_string)//注册变量到lua
            .endClass()
            .endNamespace();

    //创建test_lua对象
    test_lua test;
    luabridge::setGlobal(lua_state, &test, "test_lua");//注册test_lua对象到lua

    //运行lua脚本
    luaL_dofile(lua_state, "D:\\Users\\XMZR\\CLionProjects\\Splicing-bit-fragments\\Main_c_modules\\LuaAndCorCpp\\lua_src\\LuaBirdgeDemo1Test1.lua");

    //调用lua方法lua_add_function
    int ret = call<int>(lua_state,"lua_add_function", 5, 6);
    //调用lua方法lua_add_str_function
    std::string value = call<const char*>(lua_state,"lua_add_str_function","5", "6");
    printf("lua_add_function result:%d\n", ret);
    printf("lua_add_str_function result:%s\n", value.c_str());


    //关闭Lua
    lua_close(lua_state);

    return 0;
}
