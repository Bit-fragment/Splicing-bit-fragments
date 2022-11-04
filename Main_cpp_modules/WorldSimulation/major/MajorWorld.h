//
// Created by 20106 on 2022/11/4.
//

#ifndef STRUCTURALMODE_MAJORWORLD_H
#define STRUCTURALMODE_MAJORWORLD_H

#include <iostream>
#include <thread>
#include <utility>
#include <vector>


class World {
private:
    struct world_scale {
        int w_length = 1920;
        int w_width = 1080;
        int x = w_width / 2;
        int y = w_length / 2;
        int measure = 1;
    } ws;
public:
    World() = default;

    ~World() = default;

    static auto getWorldScale() {
        world_scale ws;
        return ws;
    }

    int getLength() const {
        return ws.w_length;
    }

    int getWidth() const {
        return ws.w_width;
    }

    int getX() const {
        return ws.x;
    }

    int getY() const {
        return ws.y;
    }

    int getWS_measure() const {
        return ws.measure;
    }


};

class Object {
private:
    World *world = nullptr;

    struct coordinate {
        int x = 0;
        int y = 0;
    } cde;

public:
    explicit Object(World *world1) {
        this->world = world1;
    }

    virtual ~Object() = default;

    auto getCDE() {
        return cde;
    }

    auto getX() const {
        return cde.x;
    }

    auto getY() const {
        return cde.y;
    }

    //在x轴上移动 type=true 代表前进 ,type=false 代表后退,移动成功返回 true
    bool moveX(bool type) {
        if (type) {
            int value = cde.x + this->world->getWS_measure();
            if (value > this->world->getLength()) {
                return false;
            }
            cde.x = value;
            return true;
        } else {
            int value = cde.x - this->world->getWS_measure();
            if (value < 0) {
                return false;
            }
            cde.x = value;
            return true;
        }

    }

    //在y轴上移动 type=true 代表前进 ,type=false 代表后退,移动成功返回 true
    bool moveY(bool type) {
        if (type) {
            int value = cde.y + this->world->getWS_measure();
            if (value > this->world->getLength()) {
                return false;
            }
            cde.y = value;
            return true;
        } else {
            int value = cde.y - this->world->getWS_measure();
            if (value < 0) {
                return false;
            }
            cde.y = value;
            return true;
        }
    }

};


class MajorWorld {
public:
    MajorWorld();

    virtual ~MajorWorld();

};


#endif //STRUCTURALMODE_MAJORWORLD_H
