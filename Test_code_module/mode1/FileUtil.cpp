//
// Created by XMZR on 2022/7/18.
//

#include <iostream>
#include <vector>
#include <cstdio>
#include "FileUtil.h"

FileUtil::FileUtil() = default;

FileUtil::~FileUtil() = default;

/*读取指定路径txt文件的内容*/
std::vector<std::string> FileUtil::readFileBody(const std::string &url) {
    /**打开文件*/
    FILE *file = fopen(url.c_str(), "rb+");
    if (nullptr == file) {  //判断是否成功打开文件
        exit(0);
    }
    /**读取文件内容*/
    std::vector<std::string> list;
    char str1[101];
    while (fgets(str1, 100, file) != nullptr) {
        list.emplace_back(str1);
    }
    /**关闭文件，关闭成功返回0 */
    if (0 != fclose(file)) {
        exit(0);
    }
    return list;
}

bool FileUtil::addFileBody(const std::string &url, const std::string &body) {
    //打开文件
    FILE *file2 = fopen(url.c_str(), "a");
    if (nullptr == file2) {  //判断是否成功打开文件
        exit(0);    //异常处理
    }

    //读取文件内容
    /*char str2;
    while ((str2 = getchar()) != '\n') {
        fputc(str2, file2);
    }*/
    fputs(body.c_str(), file2);
    /*for (char &item: body) {
        //std::cout<<item<<" ";
        fputc(item, file2);
    }*/
    //关闭文件，关闭成功返回0
    if (0 != fclose(file2)) {
        exit(0);
    }

    return true;
}



