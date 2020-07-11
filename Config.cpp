//
// Created by Edge on 2020/7/8.
//

#include <string>
#include <fstream>
#include <sstream>
#include "Config.h"
#include "Sphere.h"
#include "Triangle.h"

using namespace std;

void Config::loadConfig(const string &configFilename, Scene *scene) {
    ifstream ifs;
    ifs.open(configFilename);
    if(!ifs.is_open()) {
        std::cerr << "Error opening file " << configFilename << std::endl;
        exit(1);
    }
    string line;

    Coord eyeCoord;
    int screenWidth, screenHeight;
    Coord leftLower, leftUpper, rightLower, rightUpper;

    while(getline(ifs, line)) {
        stringstream ss(line);
        string cmd;
        ss >> cmd;
        if(cmd == "E") {
            ss >> eyeCoord;
        } else if(cmd == "O") {
            ss >> leftUpper >> rightUpper >> leftLower >> rightUpper;
        } else if(cmd == "R") {
            ss >> screenWidth >> screenHeight;
        } else if(cmd == "S") {
            Coord coord;
            float radius;
            ss >> coord;
            ss >> radius;
            scene->m_hittableList.push_back(new Sphere(coord, radius));
        } else if(cmd == "T") {
            Coord coord[3];
            for(int i = 0;i < 3;++i) {
                ss >> coord[i];
            }
            scene->m_hittableList.push_back(new Triangle(&coord));
        }
    }
    scene->m_camera = new Camera(screenWidth, screenHeight, eyeCoord, leftLower, leftUpper, rightLower, rightUpper);
}