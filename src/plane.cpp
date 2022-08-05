#include"plane.h"

plane::plane() {
    normal = glm::vec3( 0, 0, 0);
    d = 0;
}

plane::plane(glm::vec3 n, float d1) {
    normal = n;
    normal = glm::normalize(normal);
    d = d1;
}