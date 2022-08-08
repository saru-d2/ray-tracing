#ifndef SCENE_H
#define SCENE_H

#include"sphere.h"
#include<vector>
#include<variant>
#include"plane.h"
#include "ray.h"
#include"triangle.h"
#include "utils.h"
using namespace std;

class scene{
    public:
    vector_objs objs;
    scene(vector_objs objs);
    scene(){}
    bool hit(ray &r, rayInfo &rInfo, float &tMin);
};

#endif