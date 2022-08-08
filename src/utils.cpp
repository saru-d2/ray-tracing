#include "utils.h"

#include <bits/stdc++.h>

#include "../libraries/glm/gtc/random.hpp"

using namespace std;

double random_uniform() {
    static std::uniform_real_distribution<double> distribution(0.0, 1.0);
    static std::mt19937 generator;
    return distribution(generator);
}

glm::vec3 sphericalRand() { return glm::sphericalRand(1.0f); }

glm::vec3 clamp(glm::vec3 val) {
    val.x = min(val.x, 1.0f);
    val.y = min(val.y, 1.0f);
    val.z = min(val.z, 1.0f);

    return val;
}

glm::vec3 refract(glm::vec3 rayDir, glm::vec3 n, float refractive_index) {
    float cos_t = min(glm::dot(-rayDir, n), 1.0f);
    float sin_t = sqrt(1.0f - pow(cos_t, 2));

    if (sin_t * refractive_index > 1.0) {
        return reflect(rayDir, n);
    }

    glm::vec3 r_perp = refractive_index * (rayDir + cos_t * n);
    glm::vec3 r_parallel =
        (float)-sqrt(fabs(1.0 - pow(glm::length(r_perp), 2))) * n;
    return r_perp + r_parallel;
}

glm::vec3 reflect(glm::vec3 rayDir, glm::vec3 n) {
    glm::vec3 dir = rayDir - 2 * glm::dot(rayDir, n) * n;
    return dir;
}

vector<triangle> makeCube(glm::vec3 mn, glm::vec3 mx, string material,
                          glm::vec3 color) {
    glm::vec3 A = glm::vec3(mn.x, mn.y, mn.z);
    glm::vec3 B = glm::vec3(mn.x, mx.y, mn.z);
    glm::vec3 C = glm::vec3(mn.x, mn.y, mx.z);
    glm::vec3 D = glm::vec3(mn.x, mx.y, mx.z);
    glm::vec3 E = glm::vec3(mx.x, mn.y, mn.z);
    glm::vec3 F = glm::vec3(mx.x, mx.y, mn.z);
    glm::vec3 G = glm::vec3(mx.x, mn.y, mx.z);
    glm::vec3 H = glm::vec3(mx.x, mx.y, mx.z);

    vector<triangle> ret;

    ret.push_back(triangle(vector<glm::vec3>{A, C, B}, material, color));
    ret.push_back(triangle(vector<glm::vec3>{D, B, C}, material, color));

    ret.push_back(triangle(vector<glm::vec3>{A, G, C}, material, color));
    ret.push_back(triangle(vector<glm::vec3>{A, E, G}, material, color));

    ret.push_back(triangle(vector<glm::vec3>{C, H, D}, material, color));
    ret.push_back(triangle(vector<glm::vec3>{C, G, H}, material, color));

    ret.push_back(triangle(vector<glm::vec3>{B, D, H}, material, color));
    ret.push_back(triangle(vector<glm::vec3>{B, H, F}, material, color));

    ret.push_back(triangle(vector<glm::vec3>{A, B, E}, material, color));
    ret.push_back(triangle(vector<glm::vec3>{B, F, E}, material, color));

    ret.push_back(triangle(vector<glm::vec3>{E, F, G}, material, color));
    ret.push_back(triangle(vector<glm::vec3>{F, H, G}, material, color));

    return ret;
}
