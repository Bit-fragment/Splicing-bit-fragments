//
// Created by XMZR on 2022/8/2.
//

#include "main1.h"
#include <exception>
#include <iostream>
#include "../MyTextMode/MyException.h"
#include <valarray>
#include <ctime>


using namespace std;

void whileRun(long i) {
    AbstractClass *abc = (AbstractClass *) new MyClass_1(to_string(i));
    AbstractClass *abc1 = (AbstractClass *) new MyClass_2(to_string(i));
    abc->star();
    abc1->star();
    delete abc1;
    delete abc;
}

int main() {
    catFactory catF;
    dogFactory dogF;
    long p = 1;
    while (1) {
        {
            animal *cat = catF.manufacture("jiafei", p);
            animal *dog = dogF.manufacture("hapigo", p);
            cat->run();
            dog->run();
            delete (dog);
            delete (cat);
        }
        if (p == 10000)break;
        p++;
    }

    /*std::valarray<int> list(10);
    srand((int) time(0));  // 产生随机种子  把0换成NULL也行
    for (int &item: list) {
        item = rand() % 100;
        cout << item << " ";
    }
    cout << "\n" << endl;
    cout << list.max() << endl;
    cout << list.min() << endl;
    cout << list.size() << endl;
    cout << list.sum() << endl;
    cout << list.operator!() << endl;*/

    /*long i = 0;
    while (1) {
        i++;
        whileRun(i);
    }*/
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
