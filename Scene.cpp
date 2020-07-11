//
// Created by Edge on 2020/7/8.
//

#include "Scene.h"

void Scene::displayScene() {
    // TODO
    if (!m_camera) {
        return;
    }
    // Upper left start
    // Lower right end
    for (int i = 0; i < m_camera->m_height; ++i) {
        for (int j = 0; j < m_camera->m_width; ++j) {
            Ray ray = {
                    m_camera->m_eyeCoord,
                    {
                            m_camera->m_leftUpper.x + (float)j/(float)(m_camera->m_width-1)*(m_camera->m_rightUpper.x-m_camera->m_leftUpper.x) - m_camera->m_eyeCoord.x,
                            m_camera->m_leftUpper.y - (float)i/(float)(m_camera->m_height-1)*(m_camera->m_leftUpper.y-m_camera->m_leftLower.y) - m_camera->m_eyeCoord.y,
                            m_camera->m_leftUpper.z - m_camera->m_eyeCoord.z
                    }
            };
            m_camera->m_screen[i][j].r = 0.0;
            m_camera->m_screen[i][j].g = 0.0;
            m_camera->m_screen[i][j].b = 0.0;
            for(auto hittableObject: m_hittableList) {
                if(hittableObject->isHit(ray)) {
                    m_camera->m_screen[i][j].r = 255.0;
                    m_camera->m_screen[i][j].g = 255.0;
                    m_camera->m_screen[i][j].b = 255.0;
                    break;
                }
            }
        }
    }
}
