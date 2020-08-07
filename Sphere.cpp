//
// Created by Edge on 2020/7/7.
//

#include "Sphere.h"

bool Sphere::isHit(double tmin, const Ray &ray, HitRecord &record) {
    double a = ray.velocity.dot(ray.velocity);
    double b = 2 * (ray.origin - m_origin).dot(ray.velocity);
    double c = (ray.origin - m_origin).dot(ray.origin - m_origin) - m_radius * m_radius;
    double determinant = b * b - 4.0 * a * c;
    if (determinant > 0.0) {
        double t[2] = {(-b - sqrt(determinant)) / 2.0 / a, (-b + sqrt(determinant)) / 2.0 / a};
        for (double i : t) {
            if (i > tmin) {
                if (record.t < 0.0 || record.t > i) {
                    record.t = i;
                    record.point = ray.pointAt(i);
                    record.normal = record.point - m_origin;
                    record.material = m_material;
                    return true;
                }
            }
        }
    }
    return false;
}