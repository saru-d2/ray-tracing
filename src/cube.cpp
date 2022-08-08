#include"cube.h"

cube::cube(glm::vec3 n, glm::vec3 x, string mat, glm::vec3 col){
    material = mat;
    color = col;
    mn = n;
    mx = x;
}