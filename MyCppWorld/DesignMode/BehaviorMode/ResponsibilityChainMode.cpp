//
// Created by XMZR on 2022/9/6.
// 职责链模式

#include "ResponsibilityChainMode.h"

int main() {
    //mingw 编译器下,utf-8下 代码中加入 system(“chcp 65001”) 防止中文代码
    system("chcp 65001");
    Client client;
    Request request = Request("admin","password","FGDDQ234",0);
    client.run(&request);
    return 0;
}
