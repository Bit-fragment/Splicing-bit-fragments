//
// Created by XMZR on 2022/9/28.
//

#include "LuaBridgeTool.h"

template<typename R, typename T1, typename T2>
R call(lua_State *lua_state, const char *name, T1 arg1, T2 arg2) {
    //读取方法名
    lua_getglobal(lua_state, name);
    //判断是不是方法
    if (lua_isfunction(lua_state, -1)) {
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
    system("chcp 65001");
    //初始化Lua （最后记得调用lua_close(lua_state)释放）
    lua_State *lua_state = luaL_newstate();

    //加载Lua基本库
    luaL_openlibs(lua_state);
    luabridge::getGlobalNamespace(lua_state)
            .beginNamespace("test")
            .beginClass<HotServices>("HotServices")
            .addConstructor < void(*)
    (void) > ()//无参构造函数的注册
            .addData("test_str", &HotServices::HotServices_string1)//注册变量到lua
            .addStaticData("static_data", &HotServices::m_static_data)//注册静态变量到lua
            .addFunction("test", &HotServices::test)//注册test方法到lua（addStaticFunction静态函数注册也类似）
            .addProperty("name", &HotServices::GetName, &HotServices::SetName)//属性方法的注册（addStaticProperty静态属性方法也类似）
            .addCFunction("cFunc", &HotServices::cFunc)//注册返回多个参数给lua的方法
            .endClass()

            .deriveClass<HotServices_child, HotServices>("HotServices_child")//子类的注册
            .addConstructor < void(*)
    (std::string) > ()//有参构造函数的注册
            .addData("test_child_string", &HotServices_child::m_test_child_string)//注册变量到lua
            .endClass()
            .endNamespace();

    //创建HotServices对象
    HotServices hotServices;
    luabridge::setGlobal(lua_state, &hotServices, "HotServices");//注册HotServices对象到lua

    const char *url = "D:\\Users\\XMZR\\CLionProjects\\Splicing-bit-fragments\\Main_c_modules\\LuaAndCorCpp\\BusinessModules\\LuaCatalogue\\HotServices.lua";
    //运行lua脚本
    luaL_dofile(lua_state, url);

    //调用lua方法lua_add_function
    int ret = call<int>(lua_state, "lua_add_function", 5, 6);
    printf("C++调用Lua中的方法: lua_add_function() 返回值为: %d\n", ret);

    //调用lua方法lua_add_str_function
    std::string value = call<const char *>(lua_state, "lua_add_str_function", "5", "6");
    printf("C++调用Lua中的方法: lua_add_str_function() 返回值为: %s\n", value.c_str());

    int var = call<int>(lua_state,"fff",100,0);
    printf("%d",var);

    //关闭Lua
    lua_close(lua_state);
    return 0;
}