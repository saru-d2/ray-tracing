#include "ray.h"

ray::ray(glm::vec3 o, glm::vec3 d) {
    origin = o;
    dir = d;
}

glm::vec3 ray::at(float t){
    return origin + t * dir;
}

bool ray::hit(sphere s, rayInfo &rInfo, float closestSoFar, float tMin){
    glm::vec3 oc = origin - s.center;
    float a = glm::dot(dir, dir);
    float b_2 = glm::dot(oc, dir);
    float c = glm::dot(oc, oc) - s.radius*s.radius;
    auto d = b_2*b_2 - a*c;
    
    if (d < 0) return false;
    
    float t = (-b_2 - sqrt(d)) / a;
    t = min(t, (-b_2 + sqrt(d)) / a);

    if (t < tMin or t > closestSoFar) return false;

    rInfo.t = t;
    rInfo.p = at(t);
    glm::vec3 N = at(t) - s.center;
    N /= glm::length(N);
    rInfo.normal = N;

    return true;
}

// glm::vec3 ray::surfaceNormal(sphere s){
//     auto t = hit(s, rayInfo &rInfo);
//     glm::vec3 N = at(t) - s.center;
//     N /= glm::length(N);

//     return 0.5f *( N + 1.0f );
// }

bool ray::hit(plane p, rayInfo &rInfo, float closestSoFar, float tMin){
    // plane intersection
    // return -(dot(ro, p.xyz)+p.w)/dot(rdxyz);
    float t =  -(glm::dot(origin, p.normal) + p.d) / glm::dot(dir,p.normal);
    if (t < tMin or t > closestSoFar) return false;

    rInfo.t = t;
    rInfo.p = at(t);
    rInfo.normal = p.normal;

    return true;
}

// glm::vec3 ray::surfaceNormal(plane p){
//     float t = hit(p);
//     glm::vec3 N = p.normal;
//     N /= glm::length(N);

//     return 0.5f *( N + 1.0f );
// }