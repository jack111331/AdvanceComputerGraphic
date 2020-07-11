#include <iostream>

#include "Sphere.h"
#include "Scene.h"
#include "Config.h"


int main() {
    Scene *scene = new Scene();
    Config *config = new Config();
    config->loadConfig("config/hw1_input.txt", scene);
    scene->displayScene();
    scene->m_camera->toPpm("output.ppm");

    return 0;
}
