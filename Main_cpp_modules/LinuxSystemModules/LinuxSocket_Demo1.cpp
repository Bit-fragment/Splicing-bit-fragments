//
// Created by XMZR on 2022/10/9.
//
#include <iostream>
#include "LinuxSocket_Demo1.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <cstring>

//用于检查本机的字节序
void byteorder() {
    union {
        short value;
        char union_bytes[sizeof(short)];
    } test;
    test.value = 0x0102;
    if ((test.union_bytes[0] == 1) && (test.union_bytes[1] == 2)) {
        printf("\nbig endian 大端字节序");
    } else if ((test.union_bytes[0] == 2) && (test.union_bytes[1] == 1)) {
        printf("\nlittle endian 小端字节序");
    } else {
        printf("\nunknown...");
    }
}

int main() {
    FILE file;

    std::cout << "Hello world" << std::endl;
    byteorder();

    return 0;
}