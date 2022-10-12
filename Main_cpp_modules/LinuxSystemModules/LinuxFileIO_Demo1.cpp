//
// Created by 50838 on 2022/10/4.
//

#include "LinuxFileIO_Demo1.h"
#include <stdio.h>
#include <vector>

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
    /*MyFile file = MyFile("/home/xmzr/test_text.txt");
    string body = file.getMyFileBody();

    cout << "读取的内容:\n" << body;*/

    /*https://zhuanlan.zhihu.com/p/346402794*/
    /*FILE *file = fopen("/home/xmzr/test_text.txt", "a+");
    int p = 1;
    vector<char> list;
    while (p) {
        list.push_back(getc(file));
        if (feof(file)) {
            p = 0;
        }
    }
    cout << list.data() << endl;
    int type = fclose(file);
    printf("关闭文件:%d", type);*/

    DIR *dir = opendir("/home/xmzr/");
    int ty = 1;
    while (ty) {
        dirent *dirList = readdir(dir);
        if (dirList != NULL) {
            printf("\n%s", dirList->d_name);
        } else {
            ty = 0;
        }
    }
    int t1 = closedir(dir);
    printf("\n%d", t1);

    return 0;
}