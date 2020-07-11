//
// Created by Edge on 2020/7/7.
//

#ifndef ADVANCED_COMPUTER_GRAPH_SPHERE_H
#define ADVANCED_COMPUTER_GRAPH_SPHERE_H

#include "Utility.h"
#include "Ray.h"
#include "Hittable.h"

class Sphere : public Hittable {
public:
    Coord m_origin;
    float m_radius;
    Sphere(Coord origin, float radius) : m_origin(origin), m_radius(radius) {};
    virtual bool isHit(Ray &ray);
};


#endif //ADVANCED_COMPUTER_GRAPH_SPHERE_H
