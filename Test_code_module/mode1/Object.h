//
// Created by XMZR on 2022/7/27.
//

#ifndef MYCPPWORLD_OBJECT_H
#define MYCPPWORLD_OBJECT_H

class Object {
public:
    Object();

    virtual ~Object();

    std::vector<int> f1(std::vector<int> list);

    int f2(int maxValue);

    std::string f3(std::string value);

    static bool suanfa(int x, int y);

    void run(int x, int y);
};

#endif //MYCPPWORLD_OBJECT_H
