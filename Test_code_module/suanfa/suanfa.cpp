//
// Created by 20106 on 2022/10/21.
//
#include <iostream>
#include <windows.h>
using namespace std;

#define size 10

void f1(int *pi) {
    cout << "排序前: ";
    for (int i = 0; i < size; i++) {
        cout << pi[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j <= size - 1; j++) {
            if (pi[i] > pi[j]) {
                auto value = pi[i];
                pi[i] = pi[j];
                pi[j] = value;
            }
        }
    }
    cout << "排序后: ";
    for (int i = 0; i < size; i++) {
        cout << pi[i] << " ";
    }
    cout << endl;
}

auto f1(int value) {
    return &value;
}

int main() {
//    printf("hello suanfa");
//    system("chcp 65001");
//
//    int list[size] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
//    auto *list_pi = list;
//    f1(list_pi);

//    for (int i = 0; i < 1000; i++) {
//        keybd_event(VK_SPACE,0,0,0);
//        keybd_event(VK_SPACE,0,KEYEVENTF_KEYUP,0);
//    }

    POINT p;
    for (int i = 0; i < 100; i++) {
        printf("%ld , %ld\n",p.x,p.y);
        GetCursorPos(&p);//获取鼠标坐标
        SetCursorPos(p.x+3,p.y);//更改鼠标坐标
        Sleep(10);//控制移动时间间隔
    }




    return 0;
}