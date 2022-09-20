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

    return 0;
}