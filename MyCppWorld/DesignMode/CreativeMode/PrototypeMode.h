//
// Created by XMZR on 2022/9/2.
//原型是一种创建型设计模式，使你能够复制已有对象，而又无需使代码依赖它们所属的类。

#ifndef MYCPPWORLDPATTERN_PROTOTYPEMODE_H
#define MYCPPWORLDPATTERN_PROTOTYPEMODE_H

#include <string>
#include <memory>

class Prototype {
public:
    virtual Prototype *clone() = 0;//克隆

    Prototype() {std::cout << "Prototype:" << this << " is establish..." << std::endl;};

    virtual ~Prototype() {std::cout << "Prototype:" << this << " is delete..." << std::endl;};
};

class type_x : public Prototype {
private:
    std::string name;
public:
    int number = 0;
    std::string age;

    type_x(){
        this->number = 0;
        std::cout << "type_x:" << this << " is establish..." << std::endl;
    };

    ~type_x() { std::cout << "type_x:" << this << " is delete..." << std::endl;}

    void setData(std::string name, std::string age);
    std::string getData() const;
    Prototype *clone() override;
};

#endif //MYCPPWORLDPATTERN_PROTOTYPEMODE_H
