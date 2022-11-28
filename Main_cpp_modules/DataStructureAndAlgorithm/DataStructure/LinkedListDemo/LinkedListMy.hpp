//
// Created by XMZR on 2022/9/9.
//

#ifndef DATASTRUCTUREANDALGORITHM_LINKEDLISTMY_HPP
#define DATASTRUCTUREANDALGORITHM_LINKEDLISTMY_HPP

#include <iostream>

template<class T>
class Node {//定义节点
public:
    T var = {};//节点中存储的数据
    Node<T> *current = nullptr;//指向下一个节点的指针

    Node() = default;

    explicit Node(T var);
};

template<class T>
class LinkedListMy {//定义操作节点的类
private:
    Node<T> *firstNode = nullptr;//总是指向第一个节点的指针
    Node<T> *lastNode = nullptr;//总是指向最后一个节点的指针
public:
    explicit LinkedListMy();

    ~LinkedListMy();

    void addNode(T value);

    Node<T> *deleteNodeAll(Node<T> *pn);

    Node<T> *iterator(Node<T> *pn);

    Node<T> *getFirstNode();

    Node<T> *getLastNode();

    Node<T> *formatOutput(Node<T> *pn);

    Node<T> *getAppointNode(int subscript,Node<T> *pn);
};


#endif //DATASTRUCTUREANDALGORITHM_LINKEDLISTMY_HPP
