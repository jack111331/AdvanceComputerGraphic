//
// Created by Edge on 2020/7/8.
//

#ifndef ADVANCED_COMPUTER_GRAPH_SCENE_H
#define ADVANCED_COMPUTER_GRAPH_SCENE_H

#include <vector>
#include "Hittable.h"
#include "Camera.h"

class Scene {
public:
    void displayScene();
    std::vector<Hittable *> m_hittableList;
    Camera *m_camera;
};


#endif //ADVANCED_COMPUTER_GRAPH_SCENE_H
