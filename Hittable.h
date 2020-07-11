//
// Created by Edge on 2020/7/7.
//

#ifndef ADVANCED_COMPUTER_GRAPH_HITTABLE_H
#define ADVANCED_COMPUTER_GRAPH_HITTABLE_H

#include "Ray.h"

class Hittable {
public:
    virtual bool isHit(Ray &ray) = 0;
};
#endif //ADVANCED_COMPUTER_GRAPH_HITTABLE_H
