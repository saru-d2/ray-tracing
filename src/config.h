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
    int numSamplesAntiAliasing = 40;
    glm::vec3 camera_origin = glm::vec3(0, 0, 0);

    std::string display_mode = "normals";
    // std::string display_mode = "general";
    int maxDepth = 4;

    glm::vec3 lightValue = glm::vec3(3, 3, 3);
    
    glm::vec3 red = glm::vec3(1, 0, 0);
    glm::vec3 green = glm::vec3(0, 1, 0);
    glm::vec3 blue = glm::vec3(0, 0, 1);
    glm::vec3 yellow = glm::vec3(1, 1, 0);
    glm::vec3 magenta = glm::vec3(1, 0, 1);
    glm::vec3 cyan = glm::vec3(0, 1, 1);
    glm::vec3 white = glm::vec3(1, 1, 1);
    glm::vec3 cornell_gray = glm::vec3(0.5, 0.5, 0.5);

    float refractive_index = 0.6;
};

#endif