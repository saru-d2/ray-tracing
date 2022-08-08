#include"scene.h"
#include<limits>

scene::scene(vector<sphere> s1, vector<plane> p1, vector<triangle> tr1, bvh b) {
    spheres = s1;
    planes = p1;
    triangles = tr1;
    BVH = b;
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


bool scene::bvhHit(ray &r, rayInfo &rInfo, float &tMin, bvhNode *node, float &closestSoFar) {
    bool ret = false;

    if (!r.hit(node, rInfo, closestSoFar, tMin)) return false;

    if (node->l) {
        bool l = bvhHit(r, rInfo, tMin, node->l, closestSoFar);
        ret = ret || l;
    }

    if (node -> r) {
        bool R = bvhHit(r, rInfo, tMin, node->r, closestSoFar);
        ret = ret || R;
    }

    for (sphere *s: node->spheres) {
        rayInfo tempInfo;
        if (r.hit(*s, tempInfo, closestSoFar, tMin)){
            closestSoFar = tempInfo.t;
            ret = true;
            rInfo = tempInfo;
        }
    }

    for (plane *p: node->planes) {
        rayInfo tempInfo;
        if (r.hit(*p, tempInfo, closestSoFar, tMin)){
            closestSoFar = tempInfo.t;
            ret = true;
            rInfo = tempInfo;
        }
    }

    for (triangle *tr: node->triangles) {
        rayInfo tempInfo;
        if (r.hit(*tr, tempInfo, closestSoFar, tMin)){
            closestSoFar = tempInfo.t;
            ret = true;
            rInfo = tempInfo;
        }
    }

    return ret;
} 