//
// Created by XMZR on 2022/9/9.
// 主要入口函数
//#include <ctime>
#include <string>
#include <iostream>
#include "LinkedListMy.cpp"

using namespace std;

int main() {
    system("chcp 65001");

//    clock_t start, finish;//clock_t为CPU时钟计时单元数
//    start = clock();//clock()函数返回此时CPU时钟计时单元数

    LinkedListMy<int> list = LinkedListMy<int>();
    for (int i = 1; i <= 10; i++) {
        list.addNode(i);
    }
    list.formatOutput(list.getFirstNode());
    cout << "firstNode: " << list.getFirstNode()->var << endl;
    cout << "lastNode: " << list.getLastNode()->var << endl;
    cout << "getAppointNode: " << list.getAppointNode(3, list.getFirstNode())->var << endl;

//    finish = clock();//clock()函数返回此时CPU时钟计时单元数
//    //finish与start的差值即为程序运行花费的CPU时钟单元数量，再除每秒CPU有多少个时钟单元，即为程序耗时
//    std::cout << std::endl << "the time cost is:" << double(finish - start) / CLOCKS_PER_SEC << std::endl;

    return 0;
}