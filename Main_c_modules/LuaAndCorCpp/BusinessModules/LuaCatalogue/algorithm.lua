---
--- Generated by EmmyLua(https://github.com/EmmyLua)
--- Created by XMZR.
--- DateTime: 2022/9/28 14:42
---

function f1(var)
    if 1 >= var then
        return 1
    end
    return f1(var - 1) + var
end
function f2(list)
    for i = 1, #list - 1 do
        for p = i + 1, #list do
            if list[i] > list[p] then
                var = list[p]
                list[p] = list[i]
                list[i] = var
            end
        end
    end
    return list
end

local MethodList = {}
function MethodList:f1_taleb(var)
    return f1(var)
end
function MethodList:f2_taleb(list)
    return f2(list)
end

return MethodList