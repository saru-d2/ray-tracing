#include"scene.h"
#include<limits>

scene::scene(vector<sphere> s1, vector<plane> p1, vector<triangle> tr1) {
    spheres = s1;
    planes = p1;
    triangles = tr1;
}

bool scene::hit(ray &r, rayInfo &rInfo, float &tMin) {
    bool ret = false;
    float closestSoFar = std::numeric_limits<float>::max();
    for (sphere s: spheres) {
        rayInfo tempInfo;
        if (r.hit(s, tempInfo, closestSoFar, tMin)){
            closestSoFar = tempInfo.t;
            ret = true;
            rInfo = tempInfo;
        }
    }

    for (plane p: planes) {
        rayInfo tempInfo;
        if (r.hit(p, tempInfo, closestSoFar, tMin)){
            closestSoFar = tempInfo.t;
            ret = true;
            rInfo = tempInfo;
        }
    }

    for (triangle tr: triangles) {
        rayInfo tempInfo;
        if (r.hit(tr, tempInfo, closestSoFar, tMin)){
            closestSoFar = tempInfo.t;
            ret = true;
            rInfo = tempInfo;
        }
    }

    return ret;
}