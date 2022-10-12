//
// Created by XMZR on 2022/10/12.
//
#include "csapp.h"

void f1() {
    int fd1, fd2;
    char value;
    fd1 = Open("/home/xmzr/test1.txt", O_RDONLY, 0);
    fd2 = Open("/home/xmzr/test1.txt", O_RDONLY, 0);
    Read(fd1, &value, 1);
    Read(fd2, &value, 1);
    printf("value=%c\n", value);
}

void f2() {
    int fd;
    char value;
    fd = Open("/home/xmzr/test1.txt", O_RDONLY, 0);
    if (Fork() == 0) {
        Read(fd, &value, 1);
        exit(0);
    }
    Wait(NULL);
    Read(fd, &value, 1);
    printf("value=%c\n", value);
    exit(0);
}

int main() {
    //  使用命令行编译
    //  gcc -o emain Exercises.c csapp.h csapp.c -lpthread
    //  ./emain
    f1();
    printf("===========\n");
    f2();
    exit(0);
}