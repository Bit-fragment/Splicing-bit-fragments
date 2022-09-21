//
// Created by XMZR on 2022/8/2.
//

#ifndef MYCPPWORLD_MYEXCEPTION_H
#define MYCPPWORLD_MYEXCEPTION_H

class MyException {//基类（父类）
public:
    std::string msg;
    MyException(std::string msg);
    MyException();
    /*将基类的析构函数声明为虚函数之后，派生类的析构函数也自动成为虚析构函数*/
    virtual ~MyException();
    virtual void output();
    /*可以在基类中将被重写的成员函数设置为虚函数，
    其含义是：当通过基类的指针或者引用调用该成员函数时，将根据指针指向的对象类型确定调用的函数，而非指针的类型。*/
};

class Exception_1 : public MyException {//派生类（子类）
public:
    std::string msg;
    Exception_1(std::string msg);
    Exception_1();
    ~Exception_1();
    void output();
};

class Exception_2 : public Exception_1 {//派生类（孙类）
public:
    std::string msg;
    Exception_2(std::string msg);
    Exception_2();
    ~Exception_2();
    void output();
};

class AbstractClass {
public:
    /*声明为纯虚函数的析构函数仍然需要定义，但如果是其他成员函数声明为纯虚函数，则无需定义。*/
    virtual void star()const = 0;
    virtual ~AbstractClass();
};

class MyClass_1 : public AbstractClass{
public:
    std::string name;
    MyClass_1(std::string name);
    MyClass_1();
    virtual ~MyClass_1();
    /*前面使用const 表示返回值为const 后面加 const表示函数不可以修改class的成员*/
    void star()const;
};

class MyClass_2 : public AbstractClass{
public:
    std::string name;
    MyClass_2(std::string name);
    MyClass_2();
    virtual ~MyClass_2();
    void star()const;
};

#endif //MYCPPWORLD_MYEXCEPTION_H
