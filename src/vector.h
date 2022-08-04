#include<vector>

#ifndef VEC3
#define VEC3

class vec3 {
    public: 
    std::vector<double> v;
    vec3(float a, float b, float c);
    vec3();
    vec3& operator+=(vec3 &v2);
    vec3& operator*=(vec3 &v2);
    vec3 operator+=(double t);
    vec3 operator*=(double t);
    double len();
};

#endif
