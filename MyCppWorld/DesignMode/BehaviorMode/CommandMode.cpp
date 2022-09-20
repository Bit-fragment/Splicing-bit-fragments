//
// Created by XMZR on 2022/9/20.
//

#include "CommandMode.h"

int main() {
    system("chcp 65001");

    Client client(5);
    for (int i = 0; i < 10000; i++) {
        client.run(1);
        client.run(11);
    }

//    for (int i = 0; i < 10000; i++) {
//        Client client1;
//        client1.run(1);
//        client1.run(11);
//    }

    return 0;
}