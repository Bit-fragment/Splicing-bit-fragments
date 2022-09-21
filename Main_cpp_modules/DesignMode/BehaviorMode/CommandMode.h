//
// Created by XMZR on 2022/9/20.
//

#ifndef BEHAVIORMODE_COMMANDMODE_H
#define BEHAVIORMODE_COMMANDMODE_H

#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <map>

//模拟业务逻辑
class Business {
private:
    int index = -1;
public:
    explicit Business(int idx) {
        this->index = idx;
    };

    ~Business() = default;

    void Start(const std::string &messg) const {
        std::cout << "业务逻辑:" << index << "  messg is:" << messg << std::endl;
    }
};

//命令接收者(包含部分业务逻辑)
class Receiver {
private:
    std::vector<Business *> *list = nullptr;
    std::queue<int> myQueue;//命令执行队列
public:
    Receiver() = default;

    explicit Receiver(std::vector<Business *> *list) {
        this->list = list;
    };

    virtual ~Receiver() = default;

    //将命令放入执行队列
    void ReceiveCommand(int idx) {
        if (0 <= idx && idx < (*list).size()) {
            myQueue.push(idx);//放入队列
        } else {
            std::cout << "未找到可用的业务逻辑" << idx << "(加入执行队列失败)" << std::endl;
        }
    }

    //执行队列中的命令
    void ExecutionQueue() {
        if (!myQueue.empty()) {
            while (!myQueue.empty()) {
                //应当考虑将vector换成map
                (*list)[myQueue.front()]->Start("来自命令接收者的消息");
                myQueue.pop();
            }
        } else {
            std::cout << "执行队列中没有业务逻辑可执行" << std::endl;
        }
    }

    //清空队列
    void EmptyQueue() {
        while (!myQueue.empty()) {
            myQueue.pop();
        }
    }
};

//命令
class Command {
public:
    Command() = default;

    virtual ~Command() = default;

    virtual void pushQueue(int index) = 0;
};

//具体命令
class ConcreteCommands : public Command {
private:
    Receiver *receiver = nullptr;
public:
    ConcreteCommands() = default;

    explicit ConcreteCommands(Receiver *receiver) {
        this->receiver = receiver;
    };

    ~ConcreteCommands() override = default;

    void pushQueue(int index) override {//将命令放入执行队列
        receiver->ReceiveCommand(index);
    };

    void ConfirmExecute() {//执行队列中的命令
        receiver->ExecutionQueue();
    }

    void RevokeExecution() {//清空队列
        receiver->EmptyQueue();
    }
};

class Client {
private:
    ConcreteCommands concreteCommands;//具体命令
    Receiver receiver;//命令接收者
    std::vector<Business *> *list = nullptr;//初始化命令集合
public:
    explicit Client(int size) {//生成编号 1~size 的命令
        list = new std::vector<Business *>{};
        for (int i = 0; i < size; ++i) {
            auto *b1 = new Business(i);
            list->push_back(b1);
        }
        receiver = Receiver(list);
        concreteCommands = ConcreteCommands(&receiver);
    };

    ~Client() {
        std::cout << "Client析构函数执行" << std::endl;
        for (auto &i: *list) {
            delete i;
        }
        std::vector<Business *>().swap(*list);
        delete list;
    };

    void pushQueue(int index) {
        //加入队列
        concreteCommands.pushQueue(index);
    }

    void Execute() {
        //执行队列中的命令
        concreteCommands.ConfirmExecute();
        //清空队列
        concreteCommands.RevokeExecution();
    }

};

#endif //BEHAVIORMODE_COMMANDMODE_H


/** #include <queue>
 * q.empty()               如果队列为空返回true，否则返回false
 * q.size()                返回队列中元素的个数
 * q.pop()                 删除队列首元素但不返回其值
 * q.front()               返回队首元素的值，但不删除该元素
 * q.push()                在队尾压入新元素
 * q.back()                返回队列尾元素的值，但不删除该元素
 * */