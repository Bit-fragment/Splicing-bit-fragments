//
// Created by XMZR on 2022/9/1.
//

#ifndef MYCPPWORLDPATTERN_FACTORYMODE_H
#define MYCPPWORLDPATTERN_FACTORYMODE_H

#include <string>
class animal{
public:
    std::string name;
    int age{};
    animal();
    virtual ~animal();//调用析构函数，其实是调用虚函数表中的函数
    virtual void run() = 0;
};

class cat : public animal{
public:
    std::string name;
    int age{};
    cat();
    ~cat() override;// override 关键字，可以显式的在派生类中声明，哪些成员函数需要被重写，如果没被重写，则编译器会报错。
    void run() override;
};

class dog : public animal{
public:
    std::string name;
    int age{};
    dog();
    ~dog() override;
    void run() override;
};

class Factory{//工厂类
public:
    Factory();
    virtual ~Factory();
    virtual animal* manufacture(std::string name,int age) = 0;
};

class catFactory : public Factory{//具体工厂
public:
    std::string msg;
    catFactory();
    ~catFactory() override;
    cat* manufacture(std::string name,int age) override;
};

class dogFactory : public Factory{//具体工厂
public:
    std::string msg;
    dogFactory();
    ~dogFactory() override;
    dog* manufacture(std::string name,int age) override;
};

#endif //MYCPPWORLDPATTERN_FACTORYMODE_H
