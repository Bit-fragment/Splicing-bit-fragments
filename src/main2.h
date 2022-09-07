//
// Created by XMZR on 2022/8/8.
//

#ifndef MYCPPWORLD_MAIN2_H
#define MYCPPWORLD_MAIN2_H

class Object_1 {
public:
    int nabuer = 0;

    int operator+(const Object_1 &ob) const;//运算符重载
    explicit Object_1(int value);//声明为explicit的构造函数不能在隐式转换中使用
    Object_1() = default;
    /*
     * C++11允许添加“=default”说明符到函数声明的末尾，以将该函数声明为显示默认构造函数。
     * 这就使得编译器为显示默认函数生成了默认实现，它比手动编程函数更加有效。
     * */
    virtual ~Object_1() = default;
    template<class T>
    void f1(T t);
};


#endif //MYCPPWORLD_MAIN2_H
