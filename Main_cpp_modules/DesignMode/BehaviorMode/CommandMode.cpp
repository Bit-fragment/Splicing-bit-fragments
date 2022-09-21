//
// Created by XMZR on 2022/9/20.
//

#include "CommandMode.h"

int main() {
    system("chcp 65001");

    Client client(5);//生成编号1~5的命令
    client.pushQueue(1);//先执行1号命令
    client.pushQueue(3);//执行2号命令
    client.pushQueue(2);//执行3号命令
    client.pushQueue(11);//执行11号命令(不存在)
    client.Execute();//确认执行

    std::map<std::string, std::string> map1;
    map1["key1"] = "value1";
    map1["key2"] = "value2";
    map1["key3"] = "value3";
    std::map<std::string, std::string>::iterator iter;
    //在容器中寻找值为key1的元素，返回该元素的迭代器。否则，返回map.end()。
    iter = map1.find("key1");
    map1.erase(iter);//迭代器刪除
    std::cout << "map1: " << map1["key1"] << map1["key2"] << map1["key3"] << std::endl;
    //用关键字刪除
    map1.erase("key2"); //如果刪除了會返回1，否則返回0
    std::cout << "map1: " << map1["key1"] << map1["key2"] << map1["key3"] << std::endl;
    //用迭代器范围刪除 : 把整个map清空、等同于mapStudent.clear()
    map1.erase(map1.begin(), map1.end());
    std::cout << "map1: " << map1["key1"] << map1["key2"] << map1["key3"] << std::endl;

    return 0;
}