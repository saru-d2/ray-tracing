#ifndef RAY_H
#define RAY_H

#include "../libraries/glm/glm.hpp"

class ray{
    public:
    glm::vec3 origin;
    glm::vec3 dir;

    ray(glm::vec3 origin, glm::vec3 direction);
    
    glm::vec3 at(float t);
};

#endif