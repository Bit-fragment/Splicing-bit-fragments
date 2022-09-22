//
// Created by XMZR on 2022/9/22.
//
#include "DiyObjektPool.h"

template<class T>
class DiyReferenceCounter { //如何设计一个引用计数器？
private:
    T *t = nullptr;
    DiyObjektPool<T*> tp = nullptr;
public:
    DiyReferenceCounter<T>(T *t,DiyObjektPool<T*> *tp){
        this->t = t;
        this->tp = tp;
    }

    static DiyReferenceCounter<T> *produce(T *t,DiyObjektPool<T*> *tp){
        auto* drc = new DiyReferenceCounter<T>();
        return drc;
    }
};