#include"plane.h"
#include<iostream>
using std::cout, std::endl;
plane::plane() {
    normal = glm::vec3( 0, 0, 0);
    d = 0;
}

plane::plane(glm::vec3 n, float d1, string mat, glm::vec3 col) {
    normal = n;
    normal = glm::normalize(normal);
    d = d1;
    material = mat;
    color = col;
}