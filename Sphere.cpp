//
// Created by Edge on 2020/7/7.
//

#include "Sphere.h"

bool Sphere::isHit(Ray &ray) {
    Velocity rayToOrigin = m_origin - ray.origin;
    float cosTheta = ray.velocity.dot(rayToOrigin) / rayToOrigin.length() / ray.velocity.length();
    if(m_radius < rayToOrigin.length() * sqrt(1-cosTheta * cosTheta)) {
        return false;
    }
//    std::cout << "Ray Origin to Sphere Origin: " << rayToOrigin.x << " " << rayToOrigin.y << " " << rayToOrigin.z << std::endl;
//    std::cout << "Ray Velocity: " << ray.velocity.x << " " << ray.velocity.y << " " << ray.velocity.z << std::endl;
    return true;
    // float rayToSphere = rayToOrigin.length() * cosTheta - sqrt(m_radius*m_radius - rayToOrigin.length() * sqrt(1-cosTheta * cosTheta));
    // t = rayToSphere / ray.velocity.length()
}
