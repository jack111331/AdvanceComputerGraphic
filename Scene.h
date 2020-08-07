//
// Created by Edge on 2020/7/8.
//

#ifndef ADVANCED_COMPUTER_GRAPH_SCENE_H
#define ADVANCED_COMPUTER_GRAPH_SCENE_H

#include <vector>
#include "Ray.h"
#include "Light.h"
#include "Camera.h"

class HittableList;

class Scene {
public:
    Color castRay(Ray &ray, double intensity, int depth);
    void displayScene();
    HittableList *m_hittableList;
    std::vector<Light *> m_lightList;
    Camera *m_camera;
};


#endif //ADVANCED_COMPUTER_GRAPH_SCENE_H
