//
// Created by 50838 on 2022/10/4.
//

#include "LinuxFileIO_Demo1.h"

int main() {
    /*O_RDONLY、O_WRONL、O_RDWR：只读、只写、读写模式*/
    int fd = open("/home/xmzr/test_text.txt", O_RDONLY);
    if (fd == -1) {
        printf("error!");
        return fd;
    }
    printf("状态码:%d\n", fd);

    unsigned long buf;
//    ssize_t nr;
//    nr = read(fd, &word, sizeof(unsigned long));
//    if (nr == -1)printf("error");
    size_t len = sizeof(unsigned long);
    ssize_t ret;
    while (len != 0 && (ret = read(fd, &buf, len)) != 0) {
        if (ret == -1) {
            if (errno == EINTR)
                continue;
            perror("read");
            break;
        }
        len -= ret;
        buf += ret;
    }
    printf("%lu",buf);
    return 0;
}