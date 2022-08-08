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
    rInfo.material = s.material;
    rInfo.color = s.color;

    return true;
}


bool ray::hit(plane p, rayInfo &rInfo, float closestSoFar, float tMin){
    // plane intersection
    // return -(dot(ro, p.xyz)+p.w)/dot(rdxyz);
    float t =  -(glm::dot(origin, p.normal) + p.d) / glm::dot(dir,p.normal);
    if (t < tMin or t > closestSoFar) return false;

    rInfo.t = t;
    rInfo.p = at(t);
    rInfo.normal = p.normal;
    rInfo.material = p.material;
    rInfo.color = p.color;

    return true;
}

bool ray::hit(triangle tr, rayInfo &rInfo, float closestSoFar, float tMin){
    glm::vec3 rov0 = origin - tr.verts[0];
    glm::vec3  q = glm::cross( rov0, dir );
    
    
    float d = 1.0/glm::dot( dir, tr.unnormalisedNormal );
    float u = d * glm::dot( -q, tr.v2v0 );
    float v = d * glm::dot(  q, tr.v1v0 );
    float t = d * glm::dot( -tr.unnormalisedNormal, rov0 );

    // vec3  q = cross( rov0, rd );
    // float d = 1.0/dot( rd, n );
    // float u = d*dot( -q, v2v0 );
    // float v = d*dot(  q, v1v0 );
    // float t = d*dot( -n, rov0 );
    // if( u<0.0 || v<0.0 || (u+v)>1.0 ) t = -1.0;

    if( u<0.0 || v<0.0 || (u+v)>1.0 ) return false;
    
    if (t < tMin or t > closestSoFar) return false;
    
    rInfo.t = t;
    rInfo.p = at(t);
    rInfo.normal = tr.normal;
    rInfo.material = tr.material;
    rInfo.color = tr.color;

    return true;
}
