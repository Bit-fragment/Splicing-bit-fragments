//
// Created by 20106 on 2022/11/4.
//

#include <vector>
#include "MajorWorld.h"
#include "Mnoitor.cpp"

class Rendering {
private:
    World *world = nullptr;
    std::vector<Object *> list;
public:
    Rendering(World *wd, std::vector<Object *> list) {
        this->world = wd;
        this->list = std::move(list);
    }

    virtual ~Rendering() = default;

    void everyFrame() {
        for (const auto &item: list) {
            printf("x:%d,y:%d\n", item->getX(), item->getY());
        }
    }

    void initialization() {
        Object *pi = list[0];
        //启动监听键盘操作的子线程
        std::thread a([pi] {
            MonitorKeyboard(pi);
        });
        a.detach();
    }
};

