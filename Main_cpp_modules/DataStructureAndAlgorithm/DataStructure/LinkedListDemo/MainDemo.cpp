//
// Created by XMZR on 2022/9/9.
// 主要入口函数
#include <string>
#include <iostream>
#include "LinkedListMy.cpp"

using namespace std;

int main() {
    system("chcp 65001");

    LinkedListMy<int> list = LinkedListMy<int>();
    for (int i = 1; i <= 10; i++) {
        list.addNode(i);
    }
//    list.formatOutput(list.getFirstNode());
    cout << "firstNode: " << list.getFirstNode()->var << endl;
    cout << "lastNode: " << list.getLastNode()->var << endl;
    cout << "getAppointNode: " << list.getAppointNode(3, list.getFirstNode())->var << endl;

    return 0;
}