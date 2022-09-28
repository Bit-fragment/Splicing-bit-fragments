---
--- Generated by EmmyLua(https://github.com/EmmyLua)
--- Created by XMZR.
--- DateTime: 2022/9/28 9:33
---
-- 打印出当前默认搜索的动态库(so)路径
--print(package.cpath)
-- 打印当前默认的用于搜索.lua文件的路径
--print(package.path)
--package.path = package.path..";/D:/Users/XMZR/CLionProjects/Splicing-bit-fragments/Main_c_modules/LuaAndCorCpp/BusinessModules/LuaCatalogue/?.lua"
--print(package.path)

--local algorithm = require("algorithm")
--print(algorithm.f1(20))

--lua 打印lua script
print("=======执行 HotServices (Lua脚本)=======")
--调用成员变量m_test_string(test_str为注册的名字)
print("C++中的 HotServices.HotServices_string1 "..HotServices.test_str)

--调用c++静态变量（需要加上test命名空间）
test.HotServices.static_data = 12
print("C++中的 HotServices.static_data" .. test.HotServices.static_data)

--调用c++类HotServices属性name
HotServices.name = "name_property";
print("C++中的 HotServices.name " .. HotServices.name);
--lua调用c++方法HotServices为c++类在lua的注册名，调用test方法
HotServices:test(3, 4)
--print(HotServices:name("wenhao"))


--调用c++调用方法返回多个值
local var1, var2 = HotServices:cFunc()
print("C++中的 HotServices:cFunc(): var1 = " .. var1 .. " var2 = " .. var2)

--创建HotServices_child对象
local HotServices_child = test.HotServices_child("test_string")

--调用其变量
print("C++中的 HotServices_child.test_child_string:" .. HotServices_child.test_child_string);

--调用父类的name属性
HotServices_child.name = "child_name_property";
print("C++中的 HotServices_child.name" .. HotServices_child.name);


--lua 方法加法
function lua_add_function(a, b)
    print("Lua方法 lua_add_function() 被调用")
    return a + b;
end

--lua 方法字符串加法（..是相加语法）
function lua_add_str_function(a, b)
    print("Lua方法 lua_add_str_function() 被调用")
    return a .. b;
end

function fff(var)
    if 1 >= var then
        return 1
    end
    return fff(var-1)+var;
end
print("=======结束 HotServices (Lua脚本)=======")
