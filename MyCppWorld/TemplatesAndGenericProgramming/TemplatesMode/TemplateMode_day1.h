//
// Created by XMZR on 2022/9/7.
//

/*
 * 当编译器遇到一个模板定义时，它并不生成代码。只有当我们实例化出模板的一个特定版本时，编译器才会生成代码。
 * 当我们使用(而不是定义)模板时，编译器才生成代码，这一特性影响了我们如何组织代码以及错误何时被检测到。
 *
 * 通常，当我们调用一个函数时，编译器只需要掌握函数的声明。
 * 类似的，当我们使用一个类类型的对象时，类定义必须是可用的，但成员函数的定义不必已经出现。
 * 因此，我们将类定义和函数声明放在头文件中，而普通函数和类的成员函数的定义放在源文件中。
 *
 * 模板则不同:为了生成一个实例化版本，编译器需要掌握函数模板或类模板成员函数的定义。
 * 因此，与非模板代码不同，模板的头文件通常既包括声明也包括定义。
 * */

#ifndef BEHAVIORMODE_TEMPLATEMODE_DAY1_H
#define BEHAVIORMODE_TEMPLATEMODE_DAY1_H

#include <iostream>
#include <cstring>

class TemplateMode_day1 {

};

class Test_1 {
public:
    template<class T>
    T f1(const T &var1, const T &var2) {
        if (var1 < var2)return var2;
        if (var1 == var2)return 0;
        return var1;
    }

    //  unsigned 无类型整数
    template<unsigned N, unsigned M>
    /*
     * 非类型参数 可以是整数，或者是一个指向对象或函数类型的指针或（左值）引用。
     * 绑定到非类型整型参数的实参必须是一个常量表达式。
     * 绑定到指针或引用非类型参数的实参必须具有静态的生存期
     * */
    int compare(const char (&p1)[N], const char (&p2)[M]) {
        return strcmp(p1, p2);
    }
};


#endif //BEHAVIORMODE_TEMPLATEMODE_DAY1_H

/*
 * 运算符的重载，实际是一种特殊的函数重载，
 * 必须定义一个函数，并告诉C++编译器，当遇到该运算符时就调用此函数来行使运算符功能。
 * */