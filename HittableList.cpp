//
// Created by Edge on 2020/7/15.
//

#include "HittableList.h"

bool HittableList::isHit(double tmin, const Ray &ray, HitRecord &record) {
    bool isHit = false;
    for (auto hittable: m_hittableList) {
        isHit = std::max(isHit, hittable->isHit(tmin, ray, record));
    }
    return isHit;
}

void HittableList::addHittable(Hittable *hittable) {
    m_hittableList.push_back(hittable);
}