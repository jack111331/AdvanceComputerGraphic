//
// Created by Edge on 2020/7/9.
//

#include "Triangle.h"

#include <cmath>

bool Triangle::isHit(double tmin, const Ray &ray, HitRecord &record) {
    const double EPSILON = 1e-7;
    Velocity planeVector[2] = {m_point[1] - m_point[0], m_point[2] - m_point[0]};
    Velocity h = ray.velocity.cross(planeVector[1]);
    double a = planeVector[0].dot(h);
    if (std::abs(a) < EPSILON)
        return false;
    double f = 1.0 / a;
    Velocity s = ray.origin - m_point[0];
    double u = f * s.dot(h);
    if (u < 0.0 || u > 1.0)
        return false;
    Velocity q = s.cross(planeVector[0]);
    double v = f * ray.velocity.dot(q);
    if (v < 0.0 || v + u > 1.0)
        return false;

    double t = f * planeVector[1].dot(q);
    if (t > EPSILON && t > tmin) {
        if (record.t < 0.0f || record.t > t) {
            // ray.origin + t * ray.velocity is intersection point
            record.t = t;
            record.point = ray.pointAt(t);
            record.normal = planeVector[0].cross(planeVector[1]);
            record.material = m_material;
            return true;
        }
    }
    return false;
}

