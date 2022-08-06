#include"utils.h"

#include<bits/stdc++.h>

using namespace std;

double random_uniform() {
    static std::uniform_real_distribution<double> distribution(0.0, 1.0);
    static std::mt19937 generator;
    return distribution(generator);
}

glm::vec3 sphericalRand(){
    glm::vec3 randomVec = glm::vec3(random_uniform(), random_uniform(), random_uniform());
    
    return glm::normalize(randomVec);
}

