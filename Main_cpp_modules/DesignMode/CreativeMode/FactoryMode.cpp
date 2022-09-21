//
// Created by XMZR on 2022/9/1.
//
#include <iostream>
#include "FactoryMode.h"

using namespace std;

class A {
public:
    A();

    ~A() {
        cout << this << "delete...." << endl;
    };

    void run() {
        cout << this << endl;
    }
};


int main() {

    catFactory catF;
    dogFactory dogF;
    for (int i = 0; i <= 1000; i++) {
        animal *cat = catF.manufacture("jiafei", i);
        animal *dog = dogF.manufacture("hapigo", i);
        cat->run();
        dog->run();
        delete (dog);
        delete (cat);
    }
    return 0;
}

animal::animal() = default;

animal::~animal() = default;

cat::cat() = default;

cat::~cat() = default;

void cat::run() { std::cout << "I am a cat. My name is: " << this->name << ". My age is: " << this->age << endl; }

dog::dog() = default;

dog::~dog() = default;

void dog::run() { std::cout << "I am a dog. My name is: " << this->name << ". My age is: " << this->age << endl; }

Factory::Factory() = default;

Factory::~Factory() = default;

catFactory::catFactory() = default;

catFactory::~catFactory() = default;

cat *catFactory::manufacture(std::string name, int age) {
    cat *pi = new cat;
    pi->name = name;
    pi->age = age;
    return pi;
}

dogFactory::dogFactory() = default;

dogFactory::~dogFactory() = default;

dog *dogFactory::manufacture(std::string name, int age) {
    dog *pi = new dog;
    pi->name = name;
    pi->age = age;
    return pi;
}
