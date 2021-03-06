//
// Created by Edge on 2020/7/8.
//

#include <cstdint>
#include <fstream>
#include "Camera.h"

using std::ofstream;
using std::ios;

Camera::Camera(int width, int height, Coord eyeCoord, Coord leftLower, Coord leftUpper, Coord rightLower,
               Coord rightUpper) : m_width(width),
                                   m_height(height), m_eyeCoord(eyeCoord), m_leftLower(leftLower),
                                   m_leftUpper(leftUpper), m_rightLower(rightLower), m_rightUpper(rightUpper) {
    m_screen = new Color *[height];
    for (int i = 0; i < height; ++i) {
        m_screen[i] = new Color[width];
    }
}

void Camera::toPpm(const std::string &filename) {
    ofstream ofs;
    ofs.open(filename, ios::binary);
    ofs << "P6\n";
    ofs << std::to_string(m_width) << " " << std::to_string(m_height) << std::endl;
    ofs << std::to_string(255) << std::endl;


    for (int i = 0; i < m_height; ++i) {
        for (int j = 0; j < m_width; ++j) {
            ofs << m_screen[i][j];
        }
    }

}
