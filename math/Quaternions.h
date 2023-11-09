#pragma once
#include <iostream>
class Quat{

public:
   Quat(float a=0, float b=0, float c=0, float d=0);
   Quat operator+(const Quat& q) const;
   Quat operator-(const Quat& q) const;
   Quat operator*(const Quat& q) const;
   void operator=(const Quat& q);
   bool operator==(const Quat& q) const;
   bool operator!=(const Quat& q) const;
   float getA() const {return a;};
   float getB() const {return b;};
   friend std::ostream& operator<<(std::ostream& os, const Quat& q);
   
protected:
    float a;
    float b;
    float c;
    float d;
};