#include <bits/stdc++.h>

#include "../libraries/glm/glm.hpp"
#include "config.h"
#include "ray.h"
#include "scene.h"
#include "utils.h"

using namespace std;

glm::vec3 colorAtRay(ray r, scene sc) {
    // ud = unit direction
    rayInfo rInfo;

    bool h = sc.hit(r, rInfo, minDrawDist);

    rInfo.normal = glm::normalize(rInfo.normal + 1.0f);
    if (h) {
        return (rInfo.normal);
    }

    glm::vec3 ud = r.dir;
    float t = ud.x + 1.0;
    t *= 0.5f;

    return t * glm::vec3(1, 1, 1) + (float)(1.0 - t) * glm::vec3(0.3, 0.3, 1);
}

int main() {
    cout << "starting now" << endl;

    sphere sp1(glm::vec3(0, 0, -1), 0.5);
    plane p1(glm::vec3(1, 0, 0), 2);
    plane p2(glm::vec3(-1, 0, 0), 2);
    plane p3(glm::vec3(0, 1, 0), 2);
    plane p4(glm::vec3(0, -1, 0), 2);
    plane p5(glm::vec3(0, 0, 1), 3);
    scene scn(vector<sphere>{sp1}, vector<plane>{p1, p2, p3, p4, p5});

    vector<vector<vector<int>>> img(
        img_height, vector<vector<int>>(img_width, vector<int>(3, 0)));

    for (int i = 0; i < img_height; i++) {
        for (int j = 0; j < img_width; j++) {
            glm::vec3 dir(viewportOffsetH, viewportOffsetW, focal_length);
            dir.x += viewportMultiplierH * i;
            dir.y += viewportMultiplierW * j;
            dir /= glm::length(dir);
            ray rayAtPoint = ray(camera_origin, dir);
            // cout<<dir.x<<" "<<dir.y<<" "<<i<<" "<<j<<endl;
            auto color = colorAtRay(rayAtPoint, scn);
            for (int k = 0; k < 3; k += 1) {
                img[i][j][k] = color[k] * 255.0;
            }
        }
    }

    write_img(img, "output.ppm", img_height, img_width);
}