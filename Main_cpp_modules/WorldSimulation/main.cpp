//
// Created by 20106 on 2022/11/4.
//
#define OUTUPT_FORMATS system("chcp 65001");

#include <iostream>
#include "major/MajorWorld.h"
#include "tool/WTool.h"
#include "major/Rendering.cpp"
#include "tool/ObjectPool.h"

#include <pthread.h>

using namespace std;
class Test
{
public:
    Test() {}
    ~Test() {}
    void Print()
    {
        cout << "Test" << endl;
    }
};

int main() {
    OUTUPT_FORMATS
//    World world;
//    Object object = Object(&world);
//    vector<Object *> list = {&object};
//
//    Rendering rendering = Rendering(&world, list);
//    rendering.initialization();
//
//    while (type) {
////        rendering.everyFrame();
//        Sleep(2000);
//    }


    ObjectPool<Test> obj(10);
    obj.getSize();
    Test* pA;

    pA = obj.GetObject();
    pA->Print();
    obj.getSize();

    obj.ReturnObject(pA);
    obj.getSize();
    return 0;

}