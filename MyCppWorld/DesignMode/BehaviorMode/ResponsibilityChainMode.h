//
// Created by XMZR on 2022/9/6.
// 职责链模式

#ifndef STRUCTURALMODE_RESPONSIBILITYCHAINMODE_H
#define STRUCTURALMODE_RESPONSIBILITYCHAINMODE_H
#include <iostream>
#include <string>
#include <utility>

class Request {
public:
    std::string username;
    std::string password;
    std::string VCode;//验证码
    int power{};//权限  0、1、2
    Request()= default;
    Request(std::string username,std::string password,std::string VCode,int power);
    virtual ~Request()= default;
};

/*处理者（Handler）声明了所有具体处理者的通用接口。
 * 该接口通常仅包含单个方法用于请求处理，
 * 但有时其还会包含一个设置链上下个处理者的方法。*/
class Handler {// 处理者接口声明了一个创建处理者链的方法。还声明了一个执行请求的方法。
public:
    virtual void RequestProcessing(Request *request) = 0;
    Handler() = default;;
    virtual ~Handler() = default;
};

/*基础处理者（Base Handler）是一个可选的类，
 * 你可以将所有处理者共用的样本代码放置在其中。
 * 通常情况下，该类中定义了一个保存对于下个处理者引用的成员变量。
 * 客户端可通过将处理者传递给上个处理者的构造函数或设定方法来创建链。
 * 该类还可以实现默认的处理行为：确定下个处理者存在后再将请求传递给它。*/
class BaseHandler : public Handler {
public:
    BaseHandler() = default;
    ~BaseHandler() override = default;
protected:
    BaseHandler *NextObject = nullptr;
    void next(Request *request);
};

/*具体处理者（Concrete Handlers）包含处理请求的实际代码。
每个处理者接收到请求后，都必须决定是否进行处理，以及是否沿着链传递请求。
处理者通常是独立且不可变的，需要通过构造函数一次性地获得所有必要地数据。*/
class ConcreteHandlers_1 : public BaseHandler {//验证码检查
public:
    void RequestProcessing(Request *request) override;
    ConcreteHandlers_1() =default;
    explicit ConcreteHandlers_1(BaseHandler *NextObject);
    ~ConcreteHandlers_1() override =default;
};

class ConcreteHandlers_2 : public BaseHandler {//账号密码检查
public:
    void RequestProcessing(Request *request) override;
    ConcreteHandlers_2() =default;
    explicit ConcreteHandlers_2(BaseHandler *NextObject);
    ~ConcreteHandlers_2() override =default;
};

class ConcreteHandlers_3 : public BaseHandler {//权限检查
public:
    void RequestProcessing(Request *request) override;
    ConcreteHandlers_3() =default;
    explicit ConcreteHandlers_3(BaseHandler *NextObject);
    ~ConcreteHandlers_3() override =default;
};

/*客户端（Client）可根据程序逻辑一次性或者动态地生成链。
值得注意的是，请求可发送给链上的任意一个处理者，而非必须是第一个处理者。*/
class Client {
public:
    Client()= default;
    ~Client()= default;
    void processRequest(Request *request);
};


#endif //STRUCTURALMODE_RESPONSIBILITYCHAINMODE_H
