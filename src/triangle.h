#ifndef TRIANGLE_H
#define TRIANGLE_H

#include"../libraries/glm/glm.hpp"
#include<vector>
using std::vector;

class triangle{    
    public:
    vector<glm::vec3> verts;
    glm::vec3 normal;
    glm::vec3 v1v0, v2v0;

    triangle(){};
    triangle(vector<glm::vec3> verts);
    glm::vec3 getNormal();
};

#endif
