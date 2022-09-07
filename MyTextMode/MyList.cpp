//
// Created by XMZR on 2022/8/2.动态数组
//

#include <iostream>
#include "MyList.h"

MyList::MyList() {
    std::cout << "MyList()" << std::endl;
    this->size = 0;
    this->p = new int[0];
};

MyList::~MyList() {
    std::cout << "\n~MyList()" << std::endl;
    delete[] this->p;
};

MyList::MyList(int size) {
    if (0 <= size) {
        this->p = new int[size];
        this->size = size;
    }
}

int MyList::get(int var) {
    if (this->size <= var || 0 > var) {
        throw "Array out of bounds Exception......!";
    }
    return (this->p)[var];
}

void MyList::add(int value) {
    int newSize = this->size + 1;
    int *pi = new int[newSize];
    if (this->size != 0) {
        for (int i = 0; i < this->size; ++i) {
            pi[i] = this->p[i];
        }
    }
    delete[] this->p;
    this->p = pi;
    this->size = newSize;
    (this->p)[newSize - 1] = value;
}

int MyList::getSize() const {
    return this->size;
}
