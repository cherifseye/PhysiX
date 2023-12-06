#pragma once
#include <iostream>
#include <cmath>

using namespace std;
namespace PhysiX
{
class Quat{

public:
   Quat(float a=0, float b=0, float c=0, float d=0);
   Quat operator+(const Quat& q) const;
   Quat operator-(const Quat& q) const;
   Quat operator*(const Quat& q) const;
   void operator=(const Quat& q);
   bool operator==(const Quat& q) const;
   bool operator!=(const Quat& q) const;
   void operator+=(Quat& q);
   void operator-=(Quat& q);
   void operator*=(float R);
   void operator/=(float R);
   float getA() const {return a;};
   float getB() const {return b;};
   float getC() const {return c;};
   float getD() const {return d;};
   Quat Conjugate() const{return Quat(a, -b, -c, -d);};
   Quat Inverse();
   float norm() const {return sqrt(a*a + b*b + c*c + d*d);};
   Quat Rotation3d(Quat& axis, float angle);

   friend std::ostream& operator<<(std::ostream& os, const Quat& q);

protected:
    float a;
    float b;
    float c;
    float d;
};
}
