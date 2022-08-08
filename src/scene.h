#ifndef SCENE_H
#define SCENE_H

#include"sphere.h"
#include"plane.h"
#include "ray.h"
#include"triangle.h"
#include "utils.h"
#include"bvh.h"
using namespace std;

class scene{
    public:
    vector<sphere> spheres;
    vector<plane> planes;
    vector<triangle> triangles;
    bvh BVH;
    scene(vector<sphere> spheres, vector<plane>, vector<triangle>, bvh b);
    scene(){}
    bool hit(ray &r, rayInfo &rInfo, float &tMin);
    bool bvhHit(ray &r, rayInfo &rInfo, float &tMin, bvhNode *node, float &closestSoFar);
};

#endif