#include "triangle.h"
#include<iostream>
using std::cout;
using std::endl;

triangle::triangle(vector<glm::vec3> vs){
    verts = vs;
    normal = triangle::getNormal();
}

glm::vec3 triangle::getNormal() {
    glm::vec3 v0 = verts[0];
    glm::vec3 v1 = verts[1];
    glm::vec3 v2 = verts[2];
    
    v1v0 = v1 - v0;
    v2v0 = v2 - v0;
    
    glm::vec3  n = cross( v1v0, v2v0 );
    if (glm::dot(v0, n) > 0) n = -n;
    cout<<n.x<<" "<<n.y<< " "<<n.z<<endl; 
    return glm::normalize(n);
}