//
// Created by XMZR on 2022/7/27.
//
#include <vector>
#include <string>
#include <iostream>
#include <array>
#include "Object.h"

Object::Object() = default;

Object::~Object() = default;

std::vector<int> Object::f1(std::vector<int> list) {
    for (int i = 0; i < list.size() - 1; i++) {
        for (int p = i + 1; p <= list.size() - 1; p++) {
            if (list[i] > list[p]) {
                int value = list[i];
                list[i] = list[p];
                list[p] = value;
            }
        }
    }
    return list;
}

int Object::f2(int maxValue) {
    if (1 >= maxValue) {
        return 1;
    }
    return f2(maxValue - 1) + maxValue;
}

std::string Object::f3(std::string value) {
    std::string value1;
    for (int i = value.size() - 1; i >= 0; i--) {
        value1.push_back(value[i]);
    }
    std::cout << "value:" << value << std::endl;
    return value1;
}


bool Object::suanfa(int x, int y) {
    //此处定义x与y的关系
    if (y == x) {
        return true;
    } else {
        return false;
    }
//    return x == y ? true : false;
}

void Object::run(int x, int y) {
    std::array<int, 20> xList = {};
    std::array<int, 20> yList = {};
    for (int i = 0; i < 20; ++i) {
        xList.at(i) = i + 1;
        yList.at(i) = i + 1;
    }
    for (const auto &item_y: yList) {
        for (const auto &item_x: xList) {
            if (0 == item_x && 0 == item_y) {
                std::cout << "_-_";
            } else {
                if (suanfa(item_x, item_y)) {
                    std::cout << "_*_";
                } else {
                    std::cout << "_-_";
                }
            }
        }
        std::cout << std::endl;
    }
}