//
// Created by XMZR on 2022/9/1.
//
#include <iostream>
#include "BuilderMode.h"

#define size 10
using namespace std;

int main() {
//    ConcreteBuilders cb;
    /* {
         ProductsCar *list[size];
         for (int i = 0; i < size; i++) {
             {
                 cb.setShell("111");
                 cb.setEngine("222");
                 cb.setSeat("333");
                 cb.setSkeleton("444");
                 cb.setTransmission("555");
                 cb.setTyre("666");
             }
             list[i] = cb.getProduct();
             cb.reset();
         }

         std::cout << "1==============================" << std::endl;
         for (int i = 0; i < size; i++) {
             cout << i << " = " << &list[i] << " -> " << *&list[i] << ": " << list[i]->toString() << endl;
         }

         std::cout << "2==============================" << std::endl;
         for (int i = 0; i < size; i++) {
             delete list[i];
         }
     }*/
//    std::cout << "3==============================" << std::endl;
    {
//        Director director;
//        director.setBuilder(&cb);
//        ProductsCar *car2 = director.car_Ferrari(&cb);
//        ProductsCar *car3 = director.car_Lamborghini(&cb);
//
//        cout << car2->toString() << endl;
//        cout << car3->toString() << endl;
//        delete car2;
//        delete car3;
//

        Client client;
        ProductsCar *car4 = client.make_carLamborghini();
        ProductsCar *car5 = client.make_car_custom();
        cout << car4->toString() << endl;
        cout << car5->toString() << endl;
        delete car4;
        delete car5;
    }
    return 0;
}

ConcreteBuilders::ConcreteBuilders() {
    this->reset();
    std::cout << "ConcreteBuilders:" << this << " is establish..." << std::endl;
}

ConcreteBuilders::~ConcreteBuilders() {
    delete car;
    std::cout << "ConcreteBuilders:" << this << " is delete..." << std::endl;
}

//重置产品
void ConcreteBuilders::reset() {
    ConcreteBuilders::car = new ProductsCar();
}

//返回产品
ProductsCar *ConcreteBuilders::getProduct() {
    return car;
}

void ConcreteBuilders::setShell(const std::string &shell) {
    car->Shell = shell;
}

void ConcreteBuilders::setSkeleton(const std::string &skeleton) {
    car->skeleton = skeleton;
}

void ConcreteBuilders::setEngine(const std::string &engine) {
    car->engine = engine;
}

void ConcreteBuilders::setTyre(const std::string &tyre) {
    car->tyre = tyre;
}

void ConcreteBuilders::setSeat(const std::string &seat) {
    car->seat = seat;
}

void ConcreteBuilders::setTransmission(const std::string &transmission) {
    car->transmission = transmission;
}

ProductsCar *Director::car_Ferrari(ConcreteBuilders *cb) {
    cb->setShell("Ferrari_Shell");
    cb->setEngine("Ferrari_Engine");
    cb->setSeat("Ferrari_Seat");
    cb->setSkeleton("Ferrari_Skeleton");
    cb->setTransmission("Ferrari_Transmission");
    cb->setTyre("Ferrari_Tyre");
    /*ProductsCar *car = (dynamic_cast<ConcreteBuilders*>(cb))->getProduct();
    (dynamic_cast<ConcreteBuilders*>(cb))->reset();*/
    ProductsCar *car = cb->getProduct();
    cb->reset();
    return car;
}

ProductsCar *Director::car_Lamborghini(ConcreteBuilders *cb) {
    cb->setShell("Lamborghini_Shell");
    cb->setEngine("Lamborghini_Engine");
    cb->setSeat("Lamborghini_Seat");
    cb->setSkeleton("Lamborghini_Skeleton");
    cb->setTransmission("Lamborghini_Transmission");
    cb->setTyre("Lamborghini_Tyre");
    /*ProductsCar *car = (dynamic_cast<ConcreteBuilders*>(cb))->getProduct();
    (dynamic_cast<ConcreteBuilders*>(cb))->reset();*/
    ProductsCar *car = cb->getProduct();
    cb->reset();
    return car;
}
