#ifndef CUBE_H
#define CUBE_H

#include "../libraries/glm/glm.hpp"
#include<string>
using std::string;
class cube {
   public:
    std::string material;
    glm::vec3 color;
    glm::vec3 mn, mx;

    cube(){};
    cube(glm::vec3 mn, glm::vec3 mx, std::string material,
         glm::vec3 color = glm::vec3(1, 1, 1));
};

#endif