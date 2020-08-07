//
// Created by Edge on 2020/7/13.
//

#ifndef ADVANCED_COMPUTER_GRAPH_MATERIAL_H
#define ADVANCED_COMPUTER_GRAPH_MATERIAL_H


#include "Utility.h"
#include "Scene.h"
#include <iostream>

class Material {
public:
    friend std::istream &operator >> (std::istream &is, Material &rhs);

    Color calculatePhong(const Scene *scene, const Ray &ray, const HitRecord &record, const LightRecord &shadeLightRecord);

    Color m_color;
    double m_constantAmbient;
    double m_constantDiffuse;

    double m_constantSpecular;
    double m_constantSpecularExp;

    double m_constantReflectionRatio;

};


#endif //ADVANCED_COMPUTER_GRAPH_MATERIAL_H
