//
// Created by XMZR on 2022/9/16.
//

#include "FunctionDemo1.h"

int FunctionDemo1::Service1(int var) {
    for (int i = 0; i < var; i++) {
        var += 1;
    }
    return var;
}
