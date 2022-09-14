//
// Created by XMZR on 2022/9/9.
//

#ifndef DATASTRUCTUREANDALGORITHM_LINKEDLISTMY_H
#define DATASTRUCTUREANDALGORITHM_LINKEDLISTMY_H

#include <iostream>


template<class T>
class Node {//定义节点
public:
    T var = {};//节点中存储的数据
    Node<T> *current = nullptr;//指向下一个节点的指针

    Node() = default;

    explicit Node(T var) {
        this->var = var;
    }
};

template<class T>
class LinkedListMy {//定义操作节点的类
private:
    Node<T> *firstNode = nullptr;//总是指向第一个节点的指针
    Node<T> *lastNode = nullptr;//总是指向最后一个节点的指针
public:
    explicit LinkedListMy() {
        std::cout << "LinkedListMy() 构造函数被调用...." << std::endl;
    };

    ~LinkedListMy() {
        std::cout << "~LinkedListMy() 析构函数被调用...." << std::endl;
        deleteNodeAll(firstNode);//递归释放内存资源
    }

    void addNode(T value) {//在末尾添加一个节点
        if (nullptr == firstNode) {
            firstNode = new Node<T>(value);
            lastNode = firstNode;
        } else if (nullptr == lastNode->current) {
            lastNode->current = new Node<T>(value);
            lastNode = lastNode->current;
        } else {
            std::cout << "lastNode->current != null,末尾指针未移动" << std::endl;
        }
//        Node<T> *pn = iterator(firstNode);
//        pn->current = new Node<T>(value);
    }

    Node<T> *deleteNodeAll(Node<T> *pn) {//回收所有节点内存资源
        Node<T> *pi = pn->current;
        if (nullptr == pi) {
            delete pn;
            return nullptr;
        }
        delete pn;
        return deleteNodeAll(pi);
    }

    Node<T> *iterator(Node<T> *pn) {//返回从pn节点开始的 最后一个节点
        if (nullptr == pn->current)return pn;
        return iterator(pn->current);
    }

    Node<T> *getFirstNode() {//获取第一个节点指针
        return firstNode;
    }

    Node<T> *getLastNode() {//获取最后一个节点指针
        return lastNode;
    }

    Node<T> *run(Node<T> *pn) {//输出链表内容（测试）
        if (nullptr == pn->current) {
            std::cout << pn->var << std::endl;
            return nullptr;
        }
        std::cout << pn->var << " ";
        return run(pn->current);
    }

    Node<T> *getAppointNode(int subscript,Node<T> *pn) {//获取指定下标的节点指针（下标从0开始）
        if (subscript == 0) {
            return pn;
        }
        return getAppointNode(subscript - 1,pn->current);
    }
};


#endif //DATASTRUCTUREANDALGORITHM_LINKEDLISTMY_H
