//
// Created by XMZR on 2022/9/1.
//  生成器

#ifndef MYCPPWORLDPATTERN_BUILDERMODE_H
#define MYCPPWORLDPATTERN_BUILDERMODE_H

#include <string>
#include <memory>

/*产品（Products）是最终生成的对象。由不同生成器构造的产品无需属于同一类层次结构或接口。*/
class ProductsCar {
public:
    ProductsCar() {
        std::cout << "ProductsCar:" << this << " is establish..." << std::endl;
    }

    virtual ~ProductsCar() {
        std::cout << "ProductsCar:" << this << " is delete..." << std::endl;
    }

    std::string Shell;//外壳
    std::string skeleton;//骨架
    std::string engine;//引擎
    std::string tyre;//轮胎
    std::string seat;//座位
    std::string transmission;//传动装置
    std::string toString() const {
        std::string body =
                "{Shell:" + this->Shell +
                ", skeleton:" + this->skeleton +
                ", engine:" + this->engine +
                ", tyre:" + this->tyre +
                ", seat:" + this->seat +
                ", transmission:" + this->transmission + "}";
        return body;
    }

};

/*生成器（Builder）接口声明在所有类型生成器中通用的产品构造步骤。*/
class Builder {

public:

    virtual void setShell(const std::string &shell) = 0;

    virtual void setSkeleton(const std::string &skeleton) = 0;

    virtual void setEngine(const std::string &engine) = 0;

    virtual void setTyre(const std::string &tyre) = 0;

    virtual void setSeat(const std::string &seat) = 0;

    virtual void setTransmission(const std::string &transmission) = 0;

};

/*具体生成器（Concrete Builders）提供构造过程的不同实现。具体生成器也可以构造不遵循通用接口的产品。*/
class ConcreteBuilders : public Builder {
private:
    ProductsCar *car = nullptr;
public:
    ConcreteBuilders();

    virtual ~ConcreteBuilders();

    void reset();

    void setShell(const std::string &shell) override;

    void setSkeleton(const std::string &skeleton) override;

    void setEngine(const std::string &engine) override;

    void setTyre(const std::string &tyre) override;

    void setSeat(const std::string &seat) override;

    void setTransmission(const std::string &transmission) override;

    ProductsCar *getProduct();

};


/*主管（Director）类定义调用构造步骤的顺序，这样你就可以创建和复用特定的产品配置。*/
class Director {
private:
//   Builder *cb = nullptr;
public:
    Director() {
        std::cout << "Director:" << this << " is establish..." << std::endl;
    }

//    void setBuilder(ConcreteBuilders *builder) {
//        cb = dynamic_cast<ConcreteBuilders*>(builder);
//    };

    virtual ~Director() {
        std::cout << "Director:" << this << " is delete..." << std::endl;
    };

    ProductsCar *car_Ferrari(ConcreteBuilders *cb);

    ProductsCar *car_Lamborghini(ConcreteBuilders *cb);

};

/*客户端（Client）
 * 必须将某个生成器对象与主管类关联。一般情况下，你只需通过主管类构造函数的参数进行一次性关联即可。
 * 此后主管类就能使用生成器对象完成后续所有的构造任务。但在客户端将生成器对象传递给主管类制造方法时还有另一种方式。
 * 在这种情况下，你在使用主管类生产产品时每次都可以使用不同的生成器。*/
class Client {
private:
    ConcreteBuilders cb;
    Director director;
public:
    Client() { std::cout << "Client:" << this << " is establish..." << std::endl; };

    virtual ~Client() { std::cout << "Client:" << this << " is delete..." << std::endl; };

    ProductsCar *make_carLamborghini() {
        return director.car_Lamborghini(&cb);
    }

    ProductsCar *make_car_custom() {
        cb.setShell("custom_sheel");
        cb.setEngine("custom_engine");
        ProductsCar *pi = cb.getProduct();
        cb.reset();
        return pi;
    }
};


#endif //MYCPPWORLDPATTERN_BUILDERMODE_H
