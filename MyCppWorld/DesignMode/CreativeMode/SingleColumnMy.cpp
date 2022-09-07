//
// Created by XMZR on 2022/9/1.
//  实现单列模式
#include <iostream>
#include "SingleColumnMy.h"
//#include <memory>

using namespace std;

int main() {
    SingleColumnMy::getSingleColumnMy()->publicRun1();
    cout << "==============" << endl;
    SingleColumnMy my;
    my.publicRun1();
    cout << "==============" << endl;
    SingleColumnMy my1;
    my1.publicRun1();
    cout << "==============" << endl;
    SingleColumnMy *pi = new SingleColumnMy();
    pi->publicRun1();
    delete pi;
    cout << "==============" << endl;
    SingleColumnMy::getSingleColumnMy()->publicRun1();
    cout << "==============" << endl;
    return 0;
}

shared_ptr<SingleColumnMy> SingleColumnMy::me = nullptr;

SingleColumnMy::SingleColumnMy() {
    cout << this << " SingleColumnMy()" << endl;
}

SingleColumnMy::~SingleColumnMy() {
    cout << this << " ~SingleColumnMy()" << endl;
}

shared_ptr<SingleColumnMy> SingleColumnMy::getSingleColumnMy() {
    if (nullptr == me) {
        me = make_shared<SingleColumnMy>();
    }
    return me;
}

void SingleColumnMy::publicRun1() {
    cout << "publicRun1() is runing ....." << endl;
}

