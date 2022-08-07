#include "sphere.h"

sphere::sphere(glm::vec3 cen, float rad, string mat, glm::vec3 col){
    center = cen;
    radius = rad;
    material = mat;
    color = col;
}

sphere::sphere(){
    center = glm::vec3(0, 0, -1);
    radius = 0.5;
}