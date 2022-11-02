//
// Created by 20106 on 2022/11/2.
//

#include "unp.h"
#include <time.h>

int main(int argc, char **argv) {
    int listenfd, connfd;
    pid_t childpid;
    socklen_t clilen;

//    socklen_t len;
    struct sockaddr_in servaddr{}, cliaddr{};

//    char buff[MAXLINE];
//    time_t ticks;

    listenfd = Socket(AF_INET, SOCK_STREAM, 0);

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(SERV_PORT);

    Bind(listenfd, (SA *) &servaddr, sizeof(servaddr));

    Listen(listenfd, LISTENQ);

    for (;;) {
//        len = sizeof(cliaddr);
//        connfd = Accept(listenfd, (SA *) &cliaddr, &len);
//        printf("connection from %s,port %d\n",
//               Inet_ntop(AF_INET, &cliaddr.sin_addr, buff, sizeof(buff),
//                         ntohs(cliaddr.sin_port)));
//        ticks = time(NULL);
//        snprintf(buff, sizeof(buff), "%.24s\r\n", ctime(&ticks));
//        Write(connfd, buff, strlen(buff));



        Close(connfd);
    }
    return 0;
}