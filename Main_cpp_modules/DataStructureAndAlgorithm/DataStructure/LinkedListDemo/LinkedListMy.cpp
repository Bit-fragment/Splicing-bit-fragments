//
// Created by XMZR on 2022/9/9.
//

#include "LinkedListMy.hpp"

template<class T>
Node<T>::Node(T var) {
    this->var = var;
}

template<class T>
LinkedListMy<T>::LinkedListMy() {
    std::cout << "LinkedListMy() 构造函数被调用...." << std::endl;
}

template<class T>
LinkedListMy<T>::~LinkedListMy() {
    std::cout << "~LinkedListMy() 析构函数被调用...." << std::endl;
    deleteNodeAll(firstNode);//递归释放内存资源
}

template<class T>
void LinkedListMy<T>::addNode(T value) {//在末尾添加一个节点
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

template<class T>
Node<T> *LinkedListMy<T>::deleteNodeAll(Node<T> *pn) {//回收所有节点内存资源
    Node<T> *pi = pn->current;
    if (nullptr == pi) {
        delete pn;
        return nullptr;
    }
    delete pn;
    return deleteNodeAll(pi);
}

template<class T>
Node<T> *LinkedListMy<T>::iterator(Node<T> *pn) {//返回从pn节点开始的 最后一个节点
    if (nullptr == pn->current)return pn;
    return iterator(pn->current);
}

template<class T>
Node<T> *LinkedListMy<T>::getFirstNode() {//获取第一个节点指针
    return firstNode;
}

template<class T>
Node<T> *LinkedListMy<T>::getLastNode() {//获取最后一个节点指针
    return lastNode;
}

template<class T>
Node<T> *LinkedListMy<T>::formatOutput(Node<T> *pn) {//输出链表内容（测试）
    if (nullptr == pn->current) {
        std::cout << pn->var << std::endl;
        return nullptr;
    }
    std::cout << pn->var << " ";
    return formatOutput(pn->current);
}

template<class T>
Node<T> *LinkedListMy<T>::getAppointNode(int subscript, Node<T> *pn) {//获取指定下标的节点指针（下标从0开始）
    if (subscript == 0) {
        return pn;
    }
    return getAppointNode(subscript - 1, pn->current);
}
