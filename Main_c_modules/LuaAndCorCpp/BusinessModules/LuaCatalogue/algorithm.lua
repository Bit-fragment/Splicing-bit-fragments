---
--- Generated by EmmyLua(https://github.com/EmmyLua)
--- Created by XMZR.
--- DateTime: 2022/9/28 14:42
---
var = 100;

function f1(var)
    if 1 >= var then
        return 1
    end
    return f1(var - 1) + var
end