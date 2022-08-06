#ifndef CONFIG_H
#define CONFIG_H

// some common variables
#include "../libraries/glm/glm.hpp"
#include <string>

struct config {
    int img_height = 240;
    double aspect_ratio = 4.0 / 3.0;
    int img_width = img_height * aspect_ratio;

    float viewportHeight = 2.0;
    float viewportWidth = viewportHeight * aspect_ratio;
    float focal_length = -1.0;

    float viewportMultiplierH = viewportHeight / img_height;
    float viewportMultiplierW = viewportWidth / img_width;

    float viewportOffsetH = -viewportHeight / 2.0;
    float viewportOffsetW = -viewportWidth / 2.0;

    float minDrawDist = 0.001;
    int numSamplesAntiAliasing = 100;
    glm::vec3 camera_origin = glm::vec3(0, 0, 0);

    std::string display_mode = "normals";
    // std::string display_mode = "general";
    int maxDepth = 3;
};

#endif