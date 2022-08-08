#ifndef BVH_H
#define BVH_H

#include "plane.h"
#include "sphere.h"
#include "triangle.h"
#include "utils.h"

using std::vector;

class bvhNode {
   public:
    bvhNode *l = NULL, *r = NULL;
    glm::vec3 mn = glm::vec3(6, 6, 6), mx = glm::vec3(-6, -6, -6);
    bool leaf = false;
    vector<sphere *> spheres;
    vector<plane *> planes;
    vector<triangle *> triangles;

    void makeBB();
};

class bvh {
   public:
    bvhNode *root = NULL;
    void traverse();
};

#endif