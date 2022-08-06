#include <bits/stdc++.h>

#include "../libraries/glm/glm.hpp"
#include "config.h"
#include "ray.h"
#include "scene.h"
#include "utils.h"
#include "triangle.h"
#include "camera.h"

using namespace std;

int main() {
    cout << "starting now" << endl;

    config conf;


    sphere sp1(glm::vec3(0, 0, -1), 0.5);
    sphere sp2(glm::vec3(-100.5, 0, -1), 99);
    triangle tr1(vector<glm::vec3>{
        glm::vec3(1, 1, -1), 
        glm::vec3(1, 0, -1), 
        glm::vec3(0, 1, -1),
    });
    // plane p1(glm::vec3(1, 0, 0), 2);
    // plane p2(glm::vec3(-1, 0, 0), 2);
    // plane p3(glm::vec3(0, 1, 0), 2);
    // plane p4(glm::vec3(0, -1, 0), 2);
    // plane p5(glm::vec3(0, 0, 1), 3);
    scene scn(vector<sphere>{sp1, sp2}, vector<plane>{}, vector<triangle>{tr1});

    camera cam(conf, scn);
    cam.render();
    cam.write_img("output11.ppm");    
}