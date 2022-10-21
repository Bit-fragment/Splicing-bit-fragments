//
// Created by 20106 on 2022/10/21.
//
#include <iostream>

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


int main() {
//    printf("hello suanfa");
    system("chcp 65001");

    int list[size] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    auto *list_pi = list;
    f1(list_pi);

    return 0;
}