#ifndef RAY_H
#define RAY_H

#include "../libraries/glm/glm.hpp"
#include "sphere.h"
#include "plane.h"
#include "utils.h"
#include "triangle.h"
#include "bvh.h"

class ray{
    public:
    glm::vec3 origin;
    glm::vec3 dir;

    ray(glm::vec3 origin, glm::vec3 direction);
    
    glm::vec3 at(float t);

    bool hit(sphere s, rayInfo &r, float closestSoFar, float tMin);
    bool hit(plane p, rayInfo &r, float closestSoFar, float tMin);
    bool hit(triangle t, rayInfo &r, float closestSoFar, float tMin);
    bool hit(bvhNode *b, rayInfo &r, float closestSoFar, float tMin);
    // bool hit(trimesh);
};

#endif