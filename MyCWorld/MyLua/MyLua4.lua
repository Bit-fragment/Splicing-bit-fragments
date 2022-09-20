---
--- Generated by EmmyLua(https://github.com/EmmyLua)
--- Created by XMZR.
--- DateTime: 2022/9/20 16:21
---

print("hello lua world")

function f1(var)
    if var <= 1 then
        return 1
    end
    return f1(var - 1) + var
end

arrliy = { 9, 2, 1, 7, 4, 8, 5, 6, 2, 0 }
function f2(list)
    for i = 1, #list - 1 do
        for j = i + 1, #list do
            if list[i] > list[j] then
                var3 = list[i]
                list[i] = list[j]
                list[j] = var3
            end
        end
    end
    return list
end

function List_toStr(list)
    s = ""
    for i = 1, #list do
        s = s .. list[i] .. " "
    end
    return s
end

print(f1(10))

print(List_toStr(arrliy))
print(List_toStr(f2(arrliy)))

--for i = 1, 10000 do
--    print("hello lua world")
--end

-- 记录开始时间
local starttime = os.clock();                           --> os.clock()用法
print(string.format("start time : %.4f", starttime));

-- 进行耗时操作
local sum = 0;
for i = 1, 100000 do
    sum = sum + i;
    print(sum)
end

-- 记录结束时间
local endtime = os.clock();
print(string.format("end time   : %.4f", endtime));
print(string.format("cost time  : %.4f", endtime - starttime));




