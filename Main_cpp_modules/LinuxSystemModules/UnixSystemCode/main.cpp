//
// Created by 20106 on 2022/10/24.
//

#include "LinuxSystemCode.h"

using namespace std;

int main() {
    printf("Hello Cpp World  你好！\n");
    LinuxClass_1 ud;
    cout << "你好，新世界！" << ud.f1(100) << endl;

    int list_1[] = {9, 2, 1, 3, 5, 2, 0};
    auto *pi_1 = list_1;
    int size_1 = sizeof(list_1) / sizeof(int);
    cout << size_1 << "  " << pi_1[0] << endl;
    ud.f2(pi_1, size_1);
    for (auto var: list_1)
        cout << var << " ";
    cout << endl;

    double list_2[] = {9.2, 2.1, 1.6, 3.4, 5.8, 2.2, 0.6};
    auto *pi_2 = list_2;
    int size_2 = sizeof(list_2) / sizeof(double);
    cout << size_2 << "  " << pi_2[0] << endl;
    ud.f2(pi_2, size_2);
    for (auto var: list_2)
        cout << var << " ";
    cout << endl;

    return 0;
}
