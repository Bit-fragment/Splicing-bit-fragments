//
// Created by 50838 on 2022/10/4.
//

#ifndef THREADPOOL_LINUXFILEIO_DEMO1_H
#define THREADPOOL_LINUXFILEIO_DEMO1_H

#include <iostream>
#include "sys/types.h"
#include "sys/stat.h"
#include "fcntl.h"
//#include "tlpi_hdr.h"
#include <unistd.h>
#include <string>

class MyFile {
private:
    const char *url;//文件绝对路径
    int openMyFile;//标识符

public:
    MyFile();

    explicit MyFile(const std::string &url);

    ~MyFile();

    std::string getMyFileBody() const;//读取文件内容

    void fileOpen(const std::string& url);//打开一个文件

    void fileOpenat(const std::string& url);//类似于fileOpen

    void fileCreat();//创建一个文件

    void fileclose();//关闭已打开的文件

    void fileLseek();//显示地为一个打开的文件设置偏移量

    void fileRead();//从打开的文件中读数据

    void fileWrite();//向打开的文件写数据
};

MyFile::MyFile() {
    this->url = nullptr;
    this->openMyFile = -1;
}

MyFile::MyFile(const std::string &url) {
    int openType = open(url.data(), O_RDONLY);
    if (openType != -1) {
        this->url = url.data();
        this->openMyFile = openType;
    } else { printf("文件打开失败!%d", openType); }
}

MyFile::~MyFile() {
    printf("关闭文件状态码:%d", close(openMyFile));
}

std::string MyFile::getMyFileBody() const {
    char buffer[1024];
    ssize_t numRead;
    if (openMyFile != -1) {
        numRead = read(openMyFile, buffer, 1024);
        if (numRead == -1)
            printf("打开文件失败");
        buffer[numRead] = '\0';
        std::string body = std::string(buffer);
        return body;
    }
    return nullptr;
}

void MyFile::fileOpen(const std::string& url) {
    if (nullptr == this->url && this->openMyFile == -1) {
        int openType = open(this->url, O_RDONLY);
        if (openType != -1) {
            this->url = url.data();
            this->openMyFile = openType;
        } else { printf("文件打开失败!%d", openType); }
    }
}

void MyFile::fileOpenat(const std::string& url) {
    fileOpen(url);
}

void MyFile::fileCreat() {

}




#endif //THREADPOOL_LINUXFILEIO_DEMO1_H
