//
// Created by Edge on 2020/7/7.
//

#ifndef ADVANCED_COMPUTER_GRAPH_UTILITY_H
#define ADVANCED_COMPUTER_GRAPH_UTILITY_H

#include <cmath>
#include <iostream>

class Velocity {
public:
    float x, y, z;
    Velocity &operator -= (const Velocity &rhs) {
        x -= rhs.x;
        y -= rhs.y;
        z -= rhs.z;
        return *this;
    }

    Velocity operator - (const Velocity &rhs) {
        Velocity copy = *this;
        copy -= rhs;
        return copy;
    }

    float length() {
        return sqrt(x*x + y*y + z*z);
    }

    float dot(const Velocity &rhs) {
        return x*rhs.x + y*rhs.y + z*rhs.z;
    }

    Velocity cross(const Velocity &rhs) {
        return {y*rhs.z - z*rhs.y, z*rhs.x - x*rhs.z, x*rhs.y - y*rhs.x};
    }

    Velocity operator + (const Velocity &rhs) const {
        Velocity copy = {x + rhs.x, y * rhs.y, z * rhs.z};
        return copy;
    }

    Velocity operator * (float rhs) const {
        Velocity copy = {rhs * x, rhs * y, rhs * z};
        return copy;
    }

    friend Velocity operator * (float lhs, const Velocity &rhs) {
        Velocity copy = {lhs * rhs.x, lhs * rhs.y, lhs * rhs.z};
        return copy;
    }

};

class Coord {
public:
    float x, y, z;
    friend std::istream &operator >> (std::istream &is, Coord &coord) {
        is >> coord.x >> coord.y >> coord.z;
    }

    Velocity operator - (const Coord &rhs) const {
        Velocity copy = {x - rhs.x, y - rhs.y, z - rhs.z};
        return copy;
    }

    Coord operator + (const Velocity &rhs) const {
        Coord copy = {x + rhs.x, y + rhs.y, z + rhs.z};
        return copy;
    }
};

class Color {
public:
    float r, g, b;
    friend std::ostream &operator << (std::ostream &os, const Color &color) {
        os << (uint8_t)color.r << (uint8_t)color.g << (uint8_t)color.b;
    }
};


#endif //ADVANCED_COMPUTER_GRAPH_UTILITY_H
