//
// Created by XMZR on 2022/9/1.
//

#ifndef MYCWORKD_SINGLECOLUMNMY_H
#define MYCWORKD_SINGLECOLUMNMY_H

#include <memory>

//实现单列模式
class SingleColumnMy {
private:
    static std::shared_ptr<SingleColumnMy> me;

public:

    SingleColumnMy();

    virtual ~SingleColumnMy();

    static std::shared_ptr<SingleColumnMy> getSingleColumnMy();

    void publicRun1();
};


#endif //MYCWORKD_SINGLECOLUMNMY_H
