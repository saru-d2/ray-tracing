#ifndef UTILS_H
#define UTILS_H

#include<bits/stdc++.h>
#include"../libraries/glm/glm.hpp"
using namespace std;

struct rayInfo{
    float t = -1;
    glm::vec3 p = glm::vec3(0,0,0);
    glm::vec3 normal = glm::vec3(0, 0, 0);
    string material="";
    glm::vec3 color = glm::vec3(0,0,0);
};

double random_uniform();

glm::vec3 sphericalRand();

glm::vec3 clamp(glm::vec3 val);

glm::vec3 refract(glm::vec3 rayDir, glm::vec3 n, float refr);

glm::vec3 reflect(glm::vec3 rayDir, glm::vec3 n);

#endif