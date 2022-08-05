#include "ray.h"

ray::ray(glm::vec3 o, glm::vec3 d) {
    origin = o;
    dir = d;
}

glm::vec3 ray::at(float t){
    return origin + t * dir;
}