#ifndef PLANE_H
#define PLANE_H

#include "../libraries/glm/glm.hpp"
#include<string>
using std::string;

class plane {
    public:
    glm::vec3 normal;
    string material;
    glm::vec3 color;
    float d;
    plane(glm::vec3 normal, float d, string material, glm::vec3 color=glm::vec3(1, 1, 1));
    plane();
};

#endif