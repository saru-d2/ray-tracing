#ifndef TRIANGLE_H
#define TRIANGLE_H

#include"../libraries/glm/glm.hpp"
#include<vector>
#include<string>
using std::vector;
using std::string;

class triangle{    
    public:
    vector<glm::vec3> verts;
    glm::vec3 normal;
    glm::vec3 v1v0, v2v0;
    string material;
    glm::vec3 unnormalisedNormal;
    glm::vec3 color;

    triangle(){};
    triangle(vector<glm::vec3> verts, string material, glm::vec3 color=glm::vec3(1, 1, 1));
    glm::vec3 getNormal();
};

#endif
