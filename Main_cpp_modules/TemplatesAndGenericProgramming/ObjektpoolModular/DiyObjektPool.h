//
// Created by XMZR on 2022/9/22.
//

#ifndef LUAANDCORCPP_OBJEKTPOOL_H
#define LUAANDCORCPP_OBJEKTPOOL_H

#include <iostream>
#include <queue>
#include <string>

template<class T>
class DiyObjektPool {//设计一个对象池 可以放入任何对象  需要时取出，使用完放回
private:
    std::queue<T *> queue = nullptr;
    std::queue<T *> queueName = nullptr;
    std::initializer_list<T *> list = nullptr;
    std::queue<int> queueIndex;
    int size = 10;

public:
    DiyObjektPool<T>() {
        queue = new std::queue<T *>;
        queueName = new std::queue<T *>;
        for (int i = 0; i < size; i++) {
            T *t = new T();
            queue.push(t);
            queueName.push(t);
            queueIndex.push(0);

        }
    };

    ~DiyObjektPool() {
        while (!queue.empty()) {
            T *t = queue.front();
            queue.pop();//内存是否会被释放？
            delete t;
        }
        delete queue;
        queue = nullptr;
    };

    T *getObject() {//从池子中获取一个对象
        if (queue.empty())return nullptr;
        T *t = queue.front();
        queue.pop();
        return t;//如何自动回收呢？     设计一个引用计数器(类似于智能指针那种效果)
    }

    bool PutObjectBack(T *t) {
        if (nullptr == t)return false;
        while (!queue.empty()) {
            if (queue.front() == t) {
                return false;
            }
        }
        queue.push(t);
        return true;
    }
};


#endif //LUAANDCORCPP_OBJEKTPOOL_H
