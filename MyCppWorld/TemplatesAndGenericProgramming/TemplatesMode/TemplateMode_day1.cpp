//
// Created by XMZR on 2022/9/7.
//

#include "TemplateMode_day1.h"

using namespace std;

int main() {
    //mingw 编译器下,utf-8下 代码中加入 system(“chcp 65001”) 防止中文代码
    system("chcp 65001");
    Test_1 t1;
//    cout << t1.f1(1, 2) << endl;
//    cout << t1.f1(120.123123, 32.2) << endl;
//    cout << t1.f1(32.2, 32.2) << endl;


    cout << t1.compare("wh", "wenhao") << endl;
    cout << t1.compare("wenhao", "wenhao") << endl;
    cout << t1.compare("wenhao", "wh") << endl;
    return 0;
}