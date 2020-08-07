//
// Created by Edge on 2020/7/8.
//

#include <string>
#include <fstream>
#include <sstream>
#include "Config.h"
#include "Sphere.h"
#include "Triangle.h"
#include "Light.h"
#include "HittableList.h"

using namespace std;

void Config::loadConfig(const string &configFilename, Scene *scene) {
    ifstream ifs;
    ifs.open(configFilename);
    if (!ifs.is_open()) {
        std::cerr << "Error opening file " << configFilename << std::endl;
        exit(1);
    }
    string line;

    scene->m_hittableList = new HittableList();

    Coord eyeCoord;
    int screenWidth, screenHeight;
    Velocity direction, up;
    double fov;
    Material *boundMaterial = nullptr;

    while (getline(ifs, line)) {
        stringstream ss(line);
        string cmd;
        ss >> cmd;
        if (cmd == "E") {
            ss >> eyeCoord;
        } else if (cmd == "V") {
            // Viewing Direction
            ss >> direction >> up;
            direction = direction.normalize();
            up = up.normalize();
        } else if (cmd == "F") {
            ss >> fov;
        } else if (cmd == "R") {
            ss >> screenWidth >> screenHeight;
        } else if (cmd == "S") {
            if(!boundMaterial) {
                cerr << "No valid material bound in this object" << endl;
                exit(1);
            }
            Coord coord;
            double radius;
            ss >> coord;
            ss >> radius;
            Hittable *sphere = new Sphere(coord, radius);
            sphere->setMaterial(boundMaterial);
            scene->m_hittableList->addHittable(sphere);
        } else if (cmd == "T") {
            if(!boundMaterial) {
                cerr << "No valid material bound in this object" << endl;
                exit(1);
            }
            Coord coord[3];
            for (int i = 0; i < 3; ++i) {
                ss >> coord[i];
            }
            Hittable *triangle = new Triangle(&coord);
            triangle->setMaterial(boundMaterial);
            scene->m_hittableList->addHittable(triangle);
        } else if (cmd == "M") {
            boundMaterial = new Material();
            ss >> *boundMaterial;
        } else if(cmd == "L") {
            Coord lightOrigin;
            ss >> lightOrigin;
            scene->m_lightList.push_back(new Light(lightOrigin));
        }
    }
    scene->m_camera = new Camera(screenWidth, screenHeight, eyeCoord, fov, direction, up);
}