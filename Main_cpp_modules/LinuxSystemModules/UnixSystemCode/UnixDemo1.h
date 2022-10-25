//
// Created by 20106 on 2022/10/24.
//

#ifndef LINUXSYSTEMMODULES_UNIXDEMO1_H
#define LINUXSYSTEMMODULES_UNIXDEMO1_H

#include <iostream>

class UnixDemo1 {
public:
    UnixDemo1() = default;

    ~UnixDemo1() = default;

    int f1(int var);

    template<class T>
    void f2(T *pi, int pi_size);

};

int UnixDemo1::f1(int var) {
    if (var <= 1)return 1;
    return f1(var - 1) + var;
}

template<class T>
void UnixDemo1::f2(T *pi, int pi_size) {
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


#endif //LINUXSYSTEMMODULES_UNIXDEMO1_H
