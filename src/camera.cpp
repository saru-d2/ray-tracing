#include "camera.h"
#include<iostream>
#include<fstream>
#include "utils.h"

camera::camera(config c, scene sc) {
    conf = c;
    scn = sc;
    img = vector<vector<vector<int>>>(
        conf.img_height,
        vector<vector<int>>(conf.img_width, vector<int>(3, 0)));
}

void camera::render() {
    for (int i = 0; i < conf.img_height; i++) {
        for (int j = 0; j < conf.img_width; j++) {
            glm::vec3 dir(conf.viewportOffsetH, conf.viewportOffsetW,
                          conf.focal_length);
            dir.x += conf.viewportMultiplierH * i;
            dir.y += conf.viewportMultiplierW * j;
            dir /= glm::length(dir);
            ray rayAtPoint = ray(conf.camera_origin, dir);
            // cout<<dir.x<<" "<<dir.y<<" "<<i<<" "<<j<<endl;
            auto color = colorAtRay(rayAtPoint);
            for (int k = 0; k < 3; k += 1) {
                img[i][j][k] = color[k] * 255.0;
            }
        }
    }
}

glm::vec3 camera::colorAtRay(ray r) {
    rayInfo rInfo;

    bool h = scn.hit(r, rInfo, conf.minDrawDist);

    rInfo.normal = glm::normalize(rInfo.normal + 1.0f);
    if (h) {
        return (rInfo.normal);
    }

    glm::vec3 ud = r.dir;
    float t = ud.x + 1.0;
    t *= 0.5f;

    return t * glm::vec3(1, 1, 1) + (float)(1.0 - t) * glm::vec3(0.3, 0.3, 1);
}

void camera::write_img(string filename){
    ofstream f;
    cout<<"writing image";
    f.open(filename);
    f<< "P3\n" << conf.img_width << " " << conf.img_height << "\n255\n";
    for (int i =0; i<conf.img_height; i++){
        for (int j = 0; j<conf.img_width; j++){
            f<<img[i][j][0]<<" "<<img[i][j][1]<<" "<<img[i][j][2]<<"\n";
        }
    }   
    f.close();
}