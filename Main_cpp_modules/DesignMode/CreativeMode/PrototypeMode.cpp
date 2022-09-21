//
// Created by XMZR on 2022/9/2.
//原型是一种创建型设计模式，使你能够复制已有对象，而又无需使代码依赖它们所属的类。
#include <iostream>
#include <vector>
#include "PrototypeMode.h"

#define mysize 10//递归克隆数量
using namespace std;

vector<type_x *> list;//保存指针用于后续删除

//测试递归克隆
type_x *recursion(type_x *typeX) {
    if (typeX->number + 1 >= mysize) {
        list.push_back((type_x *) typeX->clone());
        return typeX;
    }
    type_x *pi = (type_x *) typeX->clone();
    list.push_back(pi);
    return recursion(pi);
}

int main() {
    type_x typeX;//创建一个原型
    typeX.setData("wenhao", "20");
    cout << "Prototype: " << typeX.getData() << endl;

    recursion(&typeX);//递归克隆

    int size = list.size();
    cout << "list.size():" << size << endl;

    for (int i = 0; i < size; i++) {
        cout << &list[i] << " " << to_string(i) << ": " << list[i]->getData() << " " << list[i] << endl;
    }

    for (int i = 0; i < size; i++) {
        delete list[i];
    }

//    type_x *pi = (type_x *) typeX.clone();
//    cout << "Clone: " << pi->getData() << endl;
//    delete pi;

    return 0;
}

Prototype *type_x::clone() {
    type_x *typeX = new type_x();
    typeX->name = this->name;
    typeX->age = this->age;
    typeX->number = this->number + 1;
    return typeX;
}

void type_x::setData(std::string name, std::string age) {
    this->name = name;
    this->age = age;
}

std::string type_x::getData() const {
//    string thisbody = string(&this);
    string body = "name:" + this->name +
                  ", age:" + this->age +
                  ", number:" + to_string(this->number) + "}";
    return body;
}
