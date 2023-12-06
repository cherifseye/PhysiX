#include <iostream>
#include "../math/Quaternions.h"

using namespace PhysiX;

int main(){
    // In this part of code we will test the quaternions class
    Quat p = {0, 1.0f, 0.25f, 1.2f};
    Quat axis = {0, 0.67f, -0.67f, -0.33f};
    cout<<p.Rotation3d(axis, 40.0f);
}