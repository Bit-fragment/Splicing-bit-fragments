//
// Created by XMZR on 2022/9/20.
//

#include "CommandMode.h"

int main() {
    system("chcp 65001");

    Client client(5);
    client.pushQueue(1);
    client.pushQueue(3);
    client.pushQueue(2);
    client.pushQueue(11);
    client.Execute();

    return 0;
}