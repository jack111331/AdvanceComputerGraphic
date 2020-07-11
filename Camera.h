//
// Created by Edge on 2020/7/8.
//

#ifndef ADVANCED_COMPUTER_GRAPH_CAMERA_H
#define ADVANCED_COMPUTER_GRAPH_CAMERA_H


#include "Utility.h"

class Camera {
public:
    Camera(int width, int height, Coord eyeCoord, Coord leftLower, Coord leftUpper, Coord rightLower, Coord rightUpper);
    void toPpm(const std::string &filename);

    int m_width, m_height;
    Color **m_screen;

    Coord m_eyeCoord;
    Coord m_leftLower, m_leftUpper, m_rightLower, m_rightUpper;
};


#endif //ADVANCED_COMPUTER_GRAPH_CAMERA_H
