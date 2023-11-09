#pragma once
#include "../../units.hpp"
#include "../../physics.hpp"
#include <cmath>
using namespace Constants;
struct Object
{
    float mass;
    float Cx;
    float radius;
    float Surface;
};

float  getV0(float mass, float Cx, float surface){
    return sqrt((2*mass * gEarth) / (Cx*pAir*surface));
}

float getT(const float V0){
    return V0/gEarth;
}
