//
// Created by XMZR on 2022/8/30.
//

#ifndef MYCPPWORLD_SERVICEOBJECT_H
#define MYCPPWORLD_SERVICEOBJECT_H
#include <vector>

class ServiceObject {

};

//数据生成器
class DataGenerator {
public:
    DataGenerator();

    ~DataGenerator();

    std::valarray<int> getRandomNumberArray(int size);
};


#endif //MYCPPWORLD_SERVICEOBJECT_H
