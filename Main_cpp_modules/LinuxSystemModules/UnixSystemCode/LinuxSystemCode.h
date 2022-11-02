//
// Created by 20106 on 2022/10/24.
//

#ifndef LinuxMain_LinuxClass_1_H
#define LinuxMain_LinuxClass_1_H

#include <iostream>
#include "netinet/in.h"

class LinuxClass_1 {
public:
    LinuxClass_1() = default;

    ~LinuxClass_1() = default;

    int f1(int var);

    template<class T>
    void f2(T *pi, int pi_size);

};
int LinuxClass_1::f1(int var) {
    if (var <= 1)return 1;
    return f1(var - 1) + var;
}
template<class T>
void LinuxClass_1::f2(T *pi, int pi_size) {
    for (int i = 0; i < pi_size - 1; i++) {
        for (int j = i + 1; j <= pi_size - 1; ++j) {
            if (pi[i] > pi[j]) {
                T var = pi[i];
                pi[i] = pi[j];
                pi[j] = var;
            }
        }
    }
}





#endif //LinuxMain_LinuxClass_1_H
