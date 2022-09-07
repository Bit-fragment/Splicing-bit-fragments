//
// Created by XMZR on 2022/8/2.
//

#include <iostream>
#include "MyException.h"

void MyException::output() { std::cout << this->msg << std::endl; }
MyException::MyException(std::string msg) : msg(msg) {}
MyException::MyException() { this->msg = "MyException"; }
MyException::~MyException() {}

void Exception_1::output() { std::cout << this->msg << std::endl; }
Exception_1::Exception_1(std::string msg) : msg(msg) {}
Exception_1::Exception_1() { this->msg = "Exception_1"; }
Exception_1::~Exception_1() {}

void Exception_2::output() { std::cout << this->msg << std::endl; }
Exception_2::Exception_2(std::string msg) : msg(msg) {}
Exception_2::Exception_2() { this->msg = "Exception_2"; }
Exception_2::~Exception_2() {}

AbstractClass::~AbstractClass() {}

void MyClass_1::star()const {std::cout << "MyClass_1::star(): " << this->name << std::endl;}
MyClass_1::MyClass_1(){this->name = "null";}
MyClass_1::MyClass_1(std::string name) : name(name) {}
MyClass_1::~MyClass_1() {}

void MyClass_2::star()const {std::cout << "MyClass_2::star(): " << this->name << std::endl;}
MyClass_2::MyClass_2(){this->name = "null";}
MyClass_2::MyClass_2(std::string name) : name(name) {}
MyClass_2::~MyClass_2() {}


