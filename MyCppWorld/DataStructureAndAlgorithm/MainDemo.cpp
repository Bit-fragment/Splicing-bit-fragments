//
// Created by XMZR on 2022/9/9.
// 主要入口函数
#include <string>
#include <iostream>
#include "LinkedListMy.h"

using namespace std;

int main() {
    LinkedListMy<int> list = LinkedListMy<int>();
    for (int i = 1; i <= 10; i++) {
        list.addNode(i);
    }
    list.run(list.getFirstNode());
    cout << "firstNode: " << list.getFirstNode()->var << endl;
    cout << "lastNode: " << list.getLastNode()->var << endl;
    cout << "getAppointNode: " << list.getAppointNode(3, list.getFirstNode())->var << endl;

//    LinkedListMy<string> list1 = LinkedListMy<string>("0");
//    list1.addNode("wenhao1");
//    list1.addNode("wenhao2");
//    list1.addNode("wenhao3");
//    list1.addNode("wenhao4");
//    list1.addNode("wenhao5");
//    list1.run(list1.getFirstNode());
    return 0;
}