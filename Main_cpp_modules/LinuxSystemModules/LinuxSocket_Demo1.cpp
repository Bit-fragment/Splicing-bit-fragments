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
        printf("big endian 大端字节序\n");
    } else if ((test.union_bytes[0] == 2) && (test.union_bytes[1] == 1)) {
        printf("little endian 小端字节序\n");
    } else {
        printf("unknown...\n");
    }
}

static bool stop = false;

static void handle_term(int sig) {
    stop = true;
}

int main(int argc, char *argv[]) {
    byteorder();
    signal(SIGTERM, handle_term);
    if (argc <= 3) {
        printf("usage:%s ip_address port_number backlog\n",
               basename(argv[0]));
        return 1;
    }
    const char *ip = argv[1];
    int port = atoi(argv[2]);
    int backlog = atoi(argv[3]);

    int sock = socket(PF_INET, SOCK_STREAM, 0);
    assert(sock >= 0);

    /*创建一个IPv4 socket地址*/
    struct sockaddr_in address;
    bzero(&address, sizeof(address));
    address.sin_family = AF_INET;
    inet_pton(AF_INET, ip, &address.sin_addr);
    address.sin_port = htons(port);

    int ret = bind(sock, (struct sockaddr *) &address, sizeof(address));
    assert(ret != -1);

    ret = listen(sock, backlog);
    assert(ret != -1);

    /*循环等待连接，直到有SIGTERM信号将他中断*/
    while (!stop) {
        sleep(1);
    }
    /*关闭socket,见后文*/
    close(sock);
    return 0;
}