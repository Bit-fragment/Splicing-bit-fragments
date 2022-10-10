//
// Created by 50838 on 2022/10/4.
//

#include "LinuxFileIO_Demo1.h"

using namespace std;

int main() {

    /*int openFile = open("/home/xmzr/test_text.txt", O_RDONLY);
    printf("文件打开后的状态码:%d\n",openFile);

    char buffer[1024];
    ssize_t numRead;
    numRead = read(openFile, buffer, 1024);
    if (numRead == -1)
        printf("打开文件失败");
    buffer[numRead] = '\0';

    printf("读取的文件内容:\n%s", buffer);

    int closeFile = close(openFile);
    printf("文件关闭后的状态码:%d",closeFile);*/
    MyFile file = MyFile("/home/xmzr/test_text.txt");
    string body = file.getMyFileBody();

    cout << "读取的内容:\n" << body;
    return 0;
}