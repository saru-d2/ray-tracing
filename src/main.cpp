#include <bits/stdc++.h>

#include "../libraries/glm/glm.hpp"
#include "config.h"
#include "ray.h"
#include "scene.h"
#include "utils.h"
#include "camera.h"

using namespace std;

int main() {
    cout << "starting now" << endl;

    config conf;


    sphere sp1(glm::vec3(0, 0, -1), 0.5);
    plane p1(glm::vec3(1, 0, 0), 2);
    plane p2(glm::vec3(-1, 0, 0), 2);
    plane p3(glm::vec3(0, 1, 0), 2);
    plane p4(glm::vec3(0, -1, 0), 2);
    plane p5(glm::vec3(0, 0, 1), 3);
    scene scn(vector<sphere>{sp1}, vector<plane>{p1, p2, p3, p4, p5});

    camera cam(conf, scn);
    cam.render();
    cam.write_img("output.ppm");    
}