#include"scene.h"
#include<limits>

scene::scene(vector_objs ob1) {
    objs = ob1;
}

bool scene::hit(ray &r, rayInfo &rInfo, float &tMin) {
    bool ret = false;
    float closestSoFar = std::numeric_limits<float>::max();
    for (auto i: objs) {
        rayInfo tempInfo;
        if (r.hit(i, tempInfo, closestSoFar, tMin)){
            closestSoFar = tempInfo.t;
            ret = true;
            rInfo = tempInfo;
        }
    }

    // for (plane p: planes) {
    //     rayInfo tempInfo;
    //     if (r.hit(p, tempInfo, closestSoFar, tMin)){
    //         closestSoFar = tempInfo.t;
    //         ret = true;
    //         rInfo = tempInfo;
    //     }
    // }

    // for (triangle tr: triangles) {
    //     rayInfo tempInfo;
    //     if (r.hit(tr, tempInfo, closestSoFar, tMin)){
    //         closestSoFar = tempInfo.t;
    //         ret = true;
    //         rInfo = tempInfo;
    //     }
    // }

    // for (cube c: cubes) {
    //     // cout<<"hiiii"<<endl;
    //     rayInfo tempInfo;
    //     if (r.hit(c, tempInfo, closestSoFar, tMin)){
    //         closestSoFar = tempInfo.t;
    //         ret = true;
    //         rInfo = tempInfo;
    //     }
    // }

    return ret;
}