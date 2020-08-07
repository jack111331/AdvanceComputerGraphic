//
// Created by Edge on 2020/7/7.
//

#ifndef ADVANCED_COMPUTER_GRAPH_UTILITY_H
#define ADVANCED_COMPUTER_GRAPH_UTILITY_H

#include <cmath>
#include <iostream>
#include <vector>

class Velocity {
public:
    double x, y, z;

    friend std::istream &operator>>(std::istream &is, Velocity &velocity) {
        is >> velocity.x >> velocity.y >> velocity.z;
    }

    Velocity &operator-=(const Velocity &rhs) {
        x -= rhs.x;
        y -= rhs.y;
        z -= rhs.z;
        return *this;
    }

    Velocity operator-() const {
        return {-x, -y, -z};
    }

    Velocity operator-(const Velocity &rhs) const {
        Velocity copy(*this);
        copy -= rhs;
        return copy;
    }

    double length() const {
        return sqrt(x * x + y * y + z * z);
    }

    double dot(const Velocity &rhs) const {
        return x * rhs.x + y * rhs.y + z * rhs.z;
    }

    Velocity cross(const Velocity &rhs) const {
        return {y * rhs.z - z * rhs.y, z * rhs.x - x * rhs.z, x * rhs.y - y * rhs.x};
    }

    Velocity reflect(const Velocity &normal) const {
        Velocity reflectedVelocity(*this);
        return reflectedVelocity - 2.0 * reflectedVelocity.dot(normal) * normal.normalize();
    }

    Velocity normalize() const {
        Velocity normalizedVelocity(*this);
        return normalizedVelocity.normalize();
    }

    Velocity &normalize() {
        double velocityLength = length();
        x /= velocityLength;
        y /= velocityLength;
        z /= velocityLength;
        return *this;
    }

    Velocity operator+(const Velocity &rhs) const {
        return {x + rhs.x, y * rhs.y, z * rhs.z};
    }

    Velocity operator*(double rhs) const {
        return  {rhs * x, rhs * y, rhs * z};
    }

    friend Velocity operator*(double lhs, const Velocity &rhs) {
        return {lhs * rhs.x, lhs * rhs.y, lhs * rhs.z};
    }

};

class Coord {
public:
    double x, y, z;

    friend std::istream &operator>>(std::istream &is, Coord &coord) {
        is >> coord.x >> coord.y >> coord.z;
    }

    Velocity operator-(const Coord &rhs) const {
        return {x - rhs.x, y - rhs.y, z - rhs.z};
    }

    Coord operator+(const Velocity &rhs) const {
        return {x + rhs.x, y + rhs.y, z + rhs.z};
    }

    Coord operator-(const Velocity &rhs) const {
        return {x - rhs.x, y - rhs.y, z - rhs.z};
    }
};

class Color {
public:
    double r, g, b;

    friend std::istream &operator>>(std::istream &is, Color &color) {
        is >> color.r >> color.g >> color.b;
    }

    friend std::ostream &operator<<(std::ostream &os, const Color &color) {
        os << (uint8_t) (255.99 * color.r) << (uint8_t) (255.99 * color.g) << (uint8_t) (255.99 * color.b);
    }

    friend Color operator*(double lhs, const Color &rhs) {
        return {lhs * rhs.r, lhs * rhs.g, lhs * rhs.b};
    }

    Color operator+(const Color &rhs) const {
        return {r + rhs.r, g + rhs.g, b + rhs.b};
    }
};

class Material;

class HitRecord {
public:
    double t;
    Coord point;
    Velocity normal;
    Material *material;
};

class LightRecord {
public:
    void addShadedLight(bool isShadedLight) {
        isShadedLightList.push_back(isShadedLight);
    }

    std::vector<bool> isShadedLightList;
};


#endif //ADVANCED_COMPUTER_GRAPH_UTILITY_H
