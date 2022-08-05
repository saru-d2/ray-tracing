#include "../libraries/glm/glm.hpp"
#include "ray.h"
#include "config.h"
#include<bits/stdc++.h>
#include "utils.h"

using namespace std;

glm::vec3 colorAtRay(ray r) {
    // ud = unit direction
    glm::vec3 ud = r.dir;
    float t= ud.x + 1.0;
    t *= 0.5;
    return t * glm::vec3(1, 1, 1) + (float)(1.0 - t) * glm::vec3(0.3, 0.3, 1); 
} 

int main(){
    cout<<"starting now"<<endl;

    vector<vector<vector<int>>> img(img_height, vector<vector<int>>(img_width, vector<int>(3, 0)));

    for (int i =0; i<img_height; i++) {
        for (int j = 0; j<img_width; j++){
            glm::vec3 dir( viewportOffsetH, viewportOffsetW,focal_length);
            dir.x += viewportMultiplierH * i;
            dir.y += viewportMultiplierW * j;
            ray rayAtPoint = ray(camera_origin, dir);
            cout<<dir.x<<" "<<dir.y<<" "<<i<<" "<<j<<endl;
            auto color = colorAtRay(rayAtPoint);
            for (int k = 0; k<3; k+=1) {
                img[i][j][k] = color[k] * 255.0;

            }
        }   
    }

    write_img(img, "output1.ppm", img_height, img_width);
}