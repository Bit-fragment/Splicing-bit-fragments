//
// Created by 20106 on 2022/11/11.
//
#define OUTUPT_FORMATS system("chcp 65001");

#include <stdio.h>
#include "fog_a/MethodeList.h"
#include <ctype.h>
#include <locale.h>

int main() {
    printf("%d \n", f1(100, 20));

//    printf("%d\n",isalnum('a'));
//    printf("%d\n",isalnum('1'));
//    printf("%d\n",isalnum(','));
//    printf("%d\n",isalnum(' '));

    printf("%c\n", tolower('R'));
    printf("%c\n", toupper('a'));

    printf("%d\n", islower('a'));
    printf("%d\n", islower('A'));

    printf("%s\n", setlocale(0, ""));


    return 0;
}