//
// Created by 20106 on 2022/11/4.
//
#define OUTUPT_FORMATS system("chcp 65001");

#include <iostream>
#include "major/MajorWorld.h"
#include "tool/WTool.h"
#include "major/Rendering.cpp"

#include <pthread.h>


int main() {
    OUTUPT_FORMATS
    World world;
    Object object = Object(&world);
    vector<Object *> list = {&object};

    Rendering rendering = Rendering(&world, list);
    rendering.initialization();

    while (type) {
//        rendering.everyFrame();
        Sleep(2000);
    }

}