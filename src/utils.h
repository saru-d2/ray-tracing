#ifndef UTILS_H
#define UTILS_H

#include<vector>
#include<string>
#include"../libraries/glm/glm.hpp"
using namespace std;

void write_img(vector<vector<vector<int>>> img, string filename, int img_height, int img_width);

struct rayInfo{
    float t = -1;
    glm::vec3 p = glm::vec3(0,0,0);
    glm::vec3 normal = glm::vec3(0, 0, 0);
};

#endif