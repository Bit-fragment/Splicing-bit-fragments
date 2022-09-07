//
// Created by XMZR on 2022/8/8.
//

#include "main2.h"
#include <iostream>
#include <vector>
#include <algorithm>//大部分算法定义在这
#include <numeric>//其中定义了一组数值泛型算法
#include "../MyTextMode/MacroDefinition/MyMacro_1.h"
#define PI 3.1416
#define MYFUNCTEN(name) { \
    std::cout<<"nimasile:"<<name<<std::endl;                    \
};

using namespace std;

int main() {
    /*int value = 20;
    vector<int> list = {7, 4, 0, 1, 9, 2};
    auto po = find(list.cbegin(), list.cend(), value);
    cout << (po == list.cend() ? "No Value" : "Yes!") << endl;

    MYFUNCTEN(value);
    cout << PI << endl;*/
    hon1;
    hon2(10);


//    MYCPPWORLD_MAIN2_H

    /*Object_1 ob1(10);
    Object_1 ob2(20);
    ob1.f1(ob1);
    cout << ob1 + ob2 << endl;*/

    /*for (int i = 0; i < 10000; i++) {
        static int p = i;//静态局部变量 在控制首次经过它的声明时才会被初始化 在其后所有的调用中，声明都会被跳过。
        {
            static int *pi = &p;
            *pi = i;
        }
        cout << "&p: " << &p << " ; p: " << p << endl;
    }*/

    return 0;
}

template<class T>
void Object_1::f1(T t) { cout << typeid(t).name() << endl; }

int Object_1::operator+(const Object_1 &ob) const { return this->nabuer + ob.nabuer; }

Object_1::Object_1(int value) { this->nabuer = value; }

//Object_1::Object_1() = default;
//
//Object_1::~Object_1() {}
