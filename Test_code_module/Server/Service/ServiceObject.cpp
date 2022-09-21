//
// Created by XMZR on 2022/8/30.
//
#include <valarray>
#include <ctime>
#include "ServiceObject.h"

DataGenerator::DataGenerator() {

}

DataGenerator::~DataGenerator() {

}

std::valarray<int> DataGenerator::getRandomNumberArray(int size) {
    std::valarray<int> list(size);
    srand((int) time(0));  // 产生随机种子  把0换成NULL也行
    for (int &item: list) {
        item = rand() % 100;
    }
    return list;
}
