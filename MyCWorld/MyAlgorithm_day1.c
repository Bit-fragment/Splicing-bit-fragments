//
// Created by XMZR on 2022/8/31.
//
#include <stdio.h>
#include <malloc.h>

#define Number 10
#define Mychar "How much time do you have?\n"

int *getList(int size) {
    int *pi = malloc(size * sizeof(int));
    if (NULL != pi) {
        for (int i = 0; i < size; i++) {
            pi[i] = i;
        }
        return pi;
    }
    return 0;
}

int main() {
    printf("%d\n", Number);
    printf(Mychar);

    printf("Hello c world!\n");
    int size = 10;
    int *pi = getList(size);
    for (int i = 0; i < size; i++) {
        printf("%d ", pi[i]);
    }
    free(pi);
}