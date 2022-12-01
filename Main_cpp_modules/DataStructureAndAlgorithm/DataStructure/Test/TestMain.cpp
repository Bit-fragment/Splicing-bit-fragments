#include <iostream>
#include <ctime>
#include <cmath>

//
// Created by 50838 on 2022/11/28.
//
int main() {

    clock_t start, finish;//clock_t为CPU时钟计时单元数
    start = clock();//clock()函数返回此时CPU时钟计时单元数

    std::cout << double(start) << std::endl;
    //你的代码
    for (int i = 2; i <= 100; i++) {
        int flag = 0;
        for (int j = 2; j <= sqrt(i); j++) {
            if (i % j == 0) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            std::cout << i << " ";
        }
    }
    finish = clock();//clock()函数返回此时CPU时钟计时单元数
    //finish与start的差值即为程序运行花费的CPU时钟单元数量，再除每秒CPU有多少个时钟单元，即为程序耗时
    std::cout << std::endl << "the time cost is:" << double(finish - start) / CLOCKS_PER_SEC << std::endl;

    std::cout << double(finish) << std::endl;
//    printf("%d\n", p);
    return 0;
}