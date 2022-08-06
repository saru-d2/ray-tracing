#ifndef SCENE_H
#define SCENE_H

#include"sphere.h"
#include<vector>
#include"plane.h"
#include "ray.h"
#include"triangle.h"
#include "utils.h"
using namespace std;

class scene{
    public:
    vector<sphere> spheres;
    vector<plane> planes;
    vector<triangle> triangles;
    scene(vector<sphere> spheres, vector<plane>, vector<triangle>);
    scene(){}
    bool hit(ray &r, rayInfo &rInfo, float &tMin);
};

#endif