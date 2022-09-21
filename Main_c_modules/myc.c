//
// Created by XMZR on 2022/8/30.
// c语言初识
//
#include <stdio.h>
#include "myc.h"

int f1(int var) {
    if (var <= 1) {
        return 1;
    }
    return f1(var - 1) + var;
}

void f2(int *pi,int size){
    for (int i = 0; i < size-1; i++) {
        for (int j = i+1; j <= size-1; j++) {
            if(pi[i]>pi[j]){
                int var = pi[i];
                pi[i] = pi[j];
                pi[j] = var;
            }
        }
    }
}

int main() {
    test();
    printf("hello c world\n");
    printf("value_int = %d\n", f1(10));

    int list[] = {21, 9, 6, 8, 3, 52, 1};
    int *pi = &list;
    printf("*pi = %d\n&pi = %d\npi[1] = %d\n", *pi,&pi,pi[1]);
    printf("sizeof(list)/4 = %d\n", sizeof(list)/4);
    printf("sizeof(pi) = %d\n", sizeof(pi));
    printf("sizeof(*pi) = %d\n", sizeof(*pi));
    int list_size = sizeof(list)/4;

    printf("Before sorting:");
    for (int i = 0; i < list_size; ++i) {
        printf(" %d",pi[i]);
    }
    f2(pi,list_size);
    printf("\nAfter sorting:");
    for (int i = 0; i < list_size; ++i) {
        printf(" %d",pi[i]);
    }
    return 0;
}