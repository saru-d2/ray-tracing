#include "triangle.h"
#include<iostream>
using std::cout;
using std::endl;

triangle::triangle(vector<glm::vec3> vs, string mat, glm::vec3 col){
    verts = vs;
    normal = triangle::getNormal();
    material = mat;
    color = col;
}

glm::vec3 triangle::getNormal() {
    glm::vec3 v0 = verts[0];
    glm::vec3 v1 = verts[1];
    glm::vec3 v2 = verts[2];
    
    v1v0 = v1 - v0;
    v2v0 = v2 - v0;
    
    glm::vec3  n = cross( v1v0, v2v0 );
    // if (glm::dot(v0, n) > 0) n = -n; 
    unnormalisedNormal = n;
    n = glm::normalize(n);
    return n;
}