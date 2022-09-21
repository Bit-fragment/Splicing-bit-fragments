//
// Created by XMZR on 2022/8/2.动态数组
//

#ifndef MYCPPWORLD_MYLIST_H
#define MYCPPWORLD_MYLIST_H

class MyList {
private:
    int size;
    int *p;
public:
    MyList(int size);

    MyList();

    ~MyList();

    int get(int size);

    void add(int value);

    int getSize() const;
};

#endif //MYCPPWORLD_MYLIST_H
