//
// Created by XMZR on 2022/9/20.
//

#ifndef BEHAVIORMODE_COMMANDMODE_H
#define BEHAVIORMODE_COMMANDMODE_H

#include <iostream>
#include <utility>
#include <vector>

//模拟业务逻辑
class Business {
private:
    int index = -1;
    int var = 3;
public:
    Business(int idx) {
        this->index = idx;
    };

    ~Business() {
//        std::cout << "Business" << index << "被销毁" << std::endl;
    };

    void run(std::string messg) {
        std::cout << var << "业务逻辑:" << index << "  messg is:" << messg << std::endl;
    }
};

//命令接收者(包含部分业务逻辑)
class Receiver {
private:
//    std::vector<Business*> list = {};
    std::vector<Business *> *list1 = nullptr;
public:
    Receiver() = default;

    explicit Receiver(std::vector<Business *> *list) {
//        this->list = std::move(list);
        this->list1 = list;
    };

    virtual ~Receiver() = default;

    void ReceiveCommand(int idx) {
//        for (auto & it : *list1){
//            std::cout << it << std::endl;
//        }
        if (0 <= idx && idx < (*list1).size()) {
//            std::cout<<(*list1).size()<<std::endl;
            (*list1)[idx]->run("来自命令接收者的消息");
//            this->list[idx]->run(idx,"来自命令接收者的消息");
        } else {
            std::cout << "没有对应业务逻辑可执行" << std::endl;
        }
    }
};

//命令
class Command {
public:
    Command() = default;

    virtual ~Command() = default;

    virtual void Execute(int index) = 0;
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

    void Execute(int index) override {
        receiver->ReceiveCommand(index);
    };
};

class Client {
public:
    ConcreteCommands concreteCommands;//具体命令
    Receiver receiver;//命令接收者
    std::vector<Business *> *list = nullptr;//初始化命令集合
    explicit Client(int size) {
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
        for (int i = 0; i < list->size(); i++) {
            delete (*list)[i];
//            (*list)[i]->run("测试是否删除");
        }
        std::vector<Business *>().swap(*list);
        delete list;
    };

    void run(int index) {
        concreteCommands.Execute(index);
    }

};


#endif //BEHAVIORMODE_COMMANDMODE_H
