//
// Created by XMZR on 2022/9/6.
// 职责链模式

#include "ResponsibilityChainMode.h"

int main() {
    //mingw 编译器下,utf-8下 代码中加入 system(“chcp 65001”) 防止中文代码
    system("chcp 65001");
    Client client;
    Request request = Request("admin", "password", "FGDDQ234", 0);
    client.processRequest(&request);
    return 0;
}

Request::Request(std::string username, std::string password, std::string VCode, int power) {
/*在C++11中，标准库在<utility>中提供了一个有用的函数std::move，std::move并不能移动任何东西，
 * 它唯一的功能是将一个左值强制转化为右值引用，继而可以通过右值引用使用该值，以用于移动语义。
 * 从实现上讲，std::move基本等同于一个类型转换：static_cast<T&&>(lvalue);
 * https://blog.csdn.net/p942005405/article/details/84644069*/
    this->username = std::move(username);
    this->password = std::move(password);
    this->VCode = std::move(VCode);
    this->power = power;
}

void BaseHandler::next(Request *request) {
    if (NextObject) {
        std::cout << "存在下一个处理者,请求传给该处理者。" << std::endl;
        NextObject->RequestProcessing(request);
    } else {
        std::cout << "不存在下一个处理者,请求处理完毕。" << std::endl;
    }
}

void ConcreteHandlers_1::RequestProcessing(Request *request) {
    std::cout << "检查 VCode: " << request->VCode << " (true or false)" << std::endl;
    if ("FGDDQ234" == request->VCode) {
        next(request);
    } else {
        std::cout << "检查 VCode 不符合要求！处理中止！FGDDQ234" << std::endl;
    }
}

ConcreteHandlers_1::ConcreteHandlers_1(BaseHandler *NextObject) {
    this->NextObject = NextObject;
}

void ConcreteHandlers_2::RequestProcessing(Request *request) {
    std::cout << "检查 username: " << request->username << " (true or false)" << std::endl;
    std::cout << "检查 password: " << request->password << " (true or false)" << std::endl;
    next(request);
}

ConcreteHandlers_2::ConcreteHandlers_2(BaseHandler *NextObject) {
    this->NextObject = NextObject;
}

void ConcreteHandlers_3::RequestProcessing(Request *request) {
    std::cout << "检查 power: " << request->power << " (true or false)" << std::endl;
    next(request);
}

ConcreteHandlers_3::ConcreteHandlers_3(BaseHandler *NextObject) {
    this->NextObject = NextObject;
}

void Client::processRequest(Request *request) {
    ConcreteHandlers_3 c3;//检查权限
    ConcreteHandlers_2 c2 = ConcreteHandlers_2(&c3);//检查账号密码
    ConcreteHandlers_1 c1 = ConcreteHandlers_1(&c2);//检查验证码
    //处理顺序 c1 -> c2 -> c3
    c1.RequestProcessing(request);
}