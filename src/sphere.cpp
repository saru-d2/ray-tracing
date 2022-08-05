#include "sphere.h"

sphere::sphere(glm::vec3 cen, float rad){
    center = cen;
    radius = rad;
}

sphere::sphere(){
    center = glm::vec3(0, 0, -1);
    radius = 0.5;
}