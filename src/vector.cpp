#include<bits/stdc++.h>
#include"vector.h"

    vec3::vec3(float a, float b, float c){
        std::cout<<a<<b<<c<<std::endl;
        v[0] = a, v[1] = b, v[2] = c;
    };

    vec3::vec3(){
        v[0] = v[1] = v[2] = 0;
    };
        
    vec3& vec3::operator+=(vec3 &v2) {
        v[0] += v2.v[0];
        v[1] += v2.v[1];
        v[2] += v2.v[2];
        return *this;
    } 

    vec3& vec3::operator*=(vec3 &v2) {
        v[0] *= v2.v[0];
        v[1] *= v2.v[1];
        v[2] *= v2.v[2];
        return *this;
    }

    vec3 vec3::operator+=(double t){
        v[0] += t;
        v[1] += t;
        v[2] += t;
        return *this;
    }

    vec3 vec3::operator*=(double t){
        v[0] *= t;
        v[1] *= t;
        v[2] *= t;
        return *this;
    }

    double vec3::len() {
        return std::sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
    }

