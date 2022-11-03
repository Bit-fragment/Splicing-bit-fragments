//
// Created by XMZR on 2022/8/30.
// c语言初识
//
#include <stdio.h>

int f1(int var) {
    if (var <= 1)return 1;
    return f1(var - 1) + var;
}


void f2(int num[], int count) {
    int i, j;
    for (i = 1; i < count; i++) {
        if (num[i] < num[i - 1]) {
            int temp = num[i];
            int left = 0, right = i - 1;
            while (left <= right) {
                int mid = (left + right) / 2;
                if (num[mid] < temp) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            //只是比较次数变少了，交换次数还是一样的
            for (j = i; j > left; j--) {
                num[j] = num[j - 1];
            }
            num[left] = temp;
        }
    }
}

int main() {
    printf("%d", 1 / 2);
    int list[] = {9, 5, 3, 27, 32, 12, 5};
    printf("\n");
    for (int i = 0; i < sizeof(list) / sizeof(int); i++) {
        printf("%d ", list[i]);
    }
    f2(list, sizeof(list) / sizeof(int));
    printf("\n");
    for (int i = 0; i < sizeof(list) / sizeof(int); i++) {
        printf("%d ", list[i]);
    }
    return 0;
}