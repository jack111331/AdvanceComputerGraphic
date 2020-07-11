//
// Created by Edge on 2020/7/9.
//

#include "Triangle.h"

bool Triangle::isHit(Ray &ray) {
    Velocity planeVector[2] = {m_point[1] - m_point[0], m_point[2] - m_point[0]};
    Velocity h = ray.velocity.cross(planeVector[1]);
    float a = planeVector[0].dot(h);
    if(fabs(a) < 1e-6)
        return false;
    float f = 1.0/a;
    Velocity s = ray.origin - m_point[0];
    float u = f * s.dot(h);
    if(u < 0.0 || u > 1.0)
        return false;
    Velocity q = s.cross(planeVector[0]);
    float v = f * ray.velocity.dot(q);
    if(v < 0.0 || v+ u > 1.0)
        return false;

    float t = f * planeVector[1].dot(q);
    if(t > 1e-6) {
        // ray.origin + t * ray.velocity is intersection point
        return true;
    }
    return false;
}