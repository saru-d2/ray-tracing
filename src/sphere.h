#ifndef SPHERE_H
#define SPHERE_H

#include"../libraries/glm/glm.hpp"
#include<string>
using std::string;

class sphere{    
    public:
    glm::vec3 center;
    string material;
    glm::vec3 color;
    float radius;
    sphere(glm::vec3 center, float radius,string material, glm::vec3 color=glm::vec3(1, 1, 1));
    sphere();
};

#endif
