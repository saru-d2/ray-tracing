#ifndef UTILS_H
#define UTILS_H

#include<bits/stdc++.h>
#include"../libraries/glm/glm.hpp"
using namespace std;

struct rayInfo{
    float t = -1;
    glm::vec3 p = glm::vec3(0,0,0);
    glm::vec3 normal = glm::vec3(0, 0, 0);
};

double random_uniform();

glm::vec3 sphericalRand();

#endif