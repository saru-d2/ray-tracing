#include"utils.h"

#include<bits/stdc++.h>
#include"../libraries/glm/gtc/random.hpp"

using namespace std;

double random_uniform() {
    static std::uniform_real_distribution<double> distribution(0.0, 1.0);
    static std::mt19937 generator;
    return distribution(generator);
}

glm::vec3 sphericalRand(){
    return glm::sphericalRand(1.0f);
}

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

    glm::vec3 r_perp =  refractive_index * (rayDir + cos_t*n);
    glm::vec3 r_parallel = (float)-sqrt(fabs(1.0 - pow(glm::length(r_perp), 2))) * n;
    return r_perp + r_parallel;
}

glm::vec3 reflect(glm::vec3 rayDir, glm::vec3 n){
    glm::vec3 dir = rayDir - 2*glm::dot(rayDir,n)*n;
    return dir;
}
