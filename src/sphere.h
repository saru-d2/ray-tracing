#ifndef SPHERE_H
#define SPHERE_H

#include"../libraries/glm/glm.hpp"

class sphere{    
    public:
    glm::vec3 center;
    float radius;
    sphere(glm::vec3 center, float radius);
    sphere();
};

#endif
