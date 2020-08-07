//
// Created by Edge on 2020/7/7.
//

#ifndef ADVANCED_COMPUTER_GRAPH_HITTABLE_H
#define ADVANCED_COMPUTER_GRAPH_HITTABLE_H

#include "Ray.h"
#include "Material.h"

class Hittable {
public:
    virtual bool isHit(double tmin, const Ray &ray, HitRecord &record) = 0;

    void setMaterial(Material *material) {
        m_material = material;
    }

    Material *m_material;

};

#endif //ADVANCED_COMPUTER_GRAPH_HITTABLE_H
