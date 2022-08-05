#ifndef PLANE_H
#define PLANE_H

#include "../libraries/glm/glm.hpp"

class plane {
    public:
    glm::vec3 normal;
    float d;
    plane(glm::vec3 normal, float d);
    plane();
};

#endif