#include "camera.h"

#include <fstream>
#include <iostream>

#include "utils.h"

camera::camera(config c, scene sc) {
    conf = c;
    scn = sc;
    img = vector<vector<vector<int>>>(
        conf.img_height,
        vector<vector<int>>(conf.img_width, vector<int>(3, 0)));
}

glm::vec3 camera::getColor(int i, int j) {
    glm::vec3 ret = glm::vec3(0, 0, 0);

    for (int it = 0; it < conf.numSamplesAntiAliasing; it += 1) {
        float ii = (float)i + random_uniform();
        float jj = (float)j + random_uniform();

        glm::vec3 dir(conf.viewportOffsetH, conf.viewportOffsetW,
                      conf.focal_length);
        dir.x += conf.viewportMultiplierH * ii;
        dir.y += conf.viewportMultiplierW * jj;
        dir /= glm::length(dir);

        ray rayAtPoint = ray(conf.camera_origin, dir);
        ret += colorAtRay(rayAtPoint, conf.maxDepth);
    }
    return ret / (float)conf.numSamplesAntiAliasing;
}

void camera::render() {
    for (int i = 0; i < conf.img_height; i++) {
        for (int j = 0; j < conf.img_width; j++) {
            auto color = getColor(i, j);
            for (int k = 0; k < 3; k += 1) {
                img[i][j][k] = color[k] * 255.0;
            }
        }
    }
}

glm::vec3 camera::colorAtRay(ray r, int depth = 1) {
    if (depth <= 0) return glm::vec3(0, 0, 0);
    rayInfo rInfo;
    bool h = scn.hit(r, rInfo, conf.minDrawDist);

    if (h) {
        if (conf.display_mode == "normals") {
            rInfo.normal = glm::normalize(rInfo.normal + 1.0f);
            return rInfo.normal;
        } else {
            glm::vec3 tar = rInfo.p + rInfo.normal + sphericalRand();
            return 0.5f * colorAtRay(ray(rInfo.p, tar - rInfo.p), depth-1);
        }
    }

    // glm::vec3 ud = r.dir;
    // float t = ud.x + 1.0;
    // t *= 0.5f;

    // return t * glm::vec3(1, 1, 1) + (float)(1.0 - t) * glm::vec3(0.3, 0.3, 1);
    return glm::vec3(0,0,0);
}

void camera::write_img(string filename) {
    ofstream f;
    cout << "writing image";
    f.open(filename);
    f << "P3\n" << conf.img_width << " " << conf.img_height << "\n255\n";
    for (int i = 0; i < conf.img_height; i++) {
        for (int j = 0; j < conf.img_width; j++) {
            f << img[i][j][0] << " " << img[i][j][1] << " " << img[i][j][2]
              << "\n";
        }
    }
    f.close();
}