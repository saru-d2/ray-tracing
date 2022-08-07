#include <bits/stdc++.h>

#include "../libraries/glm/glm.hpp"
#include "camera.h"
#include "config.h"
#include "ray.h"
#include "scene.h"
#include "triangle.h"
#include "utils.h"

using namespace std;

int main() {
    cout << "starting now" << endl;

    config conf;

    sphere sp1(glm::vec3(2, -2, -3), 1, "mirror");
    sphere sp2(glm::vec3(-0.1, 0.1, -0.8), 0.2, "glass");
    // sphere sp2(glm::vec3(-1, 1, -1), 0.2, "diffuse");
    // sphere sp3(glm::vec3(-1, -1, -1), 0.2, "diffuse");
    // sphere sp4(glm::vec3(-1, 1, -2), 0.2, "diffuse");
    // sphere sp5(glm::vec3(-1, -1, -2), 0.2, "diffuse");
    // sphere sp2(glm::vec3(-100.5, 0, -1), 99, "diffuse");
   
    //light
    triangle tr1(
        vector<glm::vec3>{
            glm::vec3(-2.9, 2, -3.5),
            glm::vec3(-2.9, 2, 0.5),
            glm::vec3(-2.9, -2, 0.5),
        },
        "light");

    triangle tr2(
        vector<glm::vec3>{
            glm::vec3(-2.9, 2, -3.5),
            glm::vec3(-2.9, -2, 0.5),
            glm::vec3(-2.9, -2, -3.5),
        },
        "light");

    // pyramid
    triangle pyr1(
        vector<glm::vec3>{
            glm::vec3(0, 0.5, -2),
            glm::vec3(0.3, 0, -2.2),
            glm::vec3(0.6, 0.5, -1.8),
        }, 
        "mirror");

    triangle pyr2(
        vector<glm::vec3>{
            glm::vec3(0, 0.5, -2),
            glm::vec3(0.6, 0.5, -1.8),
            glm::vec3(0.3, 1, -2.2),
        }, 
        "mirror");

    triangle pyr3(
        vector<glm::vec3>{
            glm::vec3(0.6, 0.5, -1.8),
            glm::vec3(0.3, 0, -2.2),
            glm::vec3(0.3, 1, -2.2),
        }, 
        "mirror");

    triangle pyr4(
        vector<glm::vec3>{
            glm::vec3(0, 0.5, -2),
            glm::vec3(0.3, 1, -2.2),
            glm::vec3(0.3, 0, -2.2),
        }, 
        "mirror");
        

    plane p1(glm::vec3(-1, 0, 0), 3, "checker", conf.cornell_gray);
    plane p2(glm::vec3(1, 0, 0), 3, "diffuse", conf.cornell_gray);
    plane p3(glm::vec3(0, 1, 0), 3, "diffuse", conf.green);
    plane p4(glm::vec3(0, -1, 0), 3, "diffuse", conf.red);
    plane p5(glm::vec3(0, 0, 1), 4, "diffuse", conf.cornell_gray);
    plane p6(glm::vec3(0, 0, -1), 0.5, "diffuse", conf.cornell_gray);


    scene scn(vector<sphere>{sp1, sp2}, vector<plane>{p1, p2, p3, p4, p5},
              vector<triangle>{tr1, tr2, pyr1, pyr2, pyr3, pyr4});

    camera cam(conf, scn);

    cam.render();
    cam.write_img("output11.ppm");
}