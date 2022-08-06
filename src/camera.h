#ifndef CAMERA_H
#define CAMERA_H

#include "config.h"
#include "scene.h"
#include "ray.h"

class camera {
   public:
    config conf;
    scene scn;
    vector<vector<vector<int>>> img;
    camera(config c, scene sc);
    camera(){};
    void render();
    glm::vec3 getColor(int i, int j);
    void write_img(std::string filename);
    glm::vec3 colorAtRay(ray r, int depth);
};

#endif