#include <iostream>
#include "Quaternions.h"


using namespace PhysiX;
Quat:: Quat(float x, float y, float z, float k){
    a = x;
    b = y;
    c = z;
    d = k;
}

Quat Quat::operator+(const Quat& q) const{
    return Quat((a + q.a), (b+q.b), (c+q.c), (d + q.d));
}

Quat Quat::operator-(const Quat& q) const{
    return Quat((a - q.a), (b- q.b), (c -q.c), (d - q.d));
}

Quat Quat::operator*(const Quat& q) const{
    float t0, i, j, k;
    t0 = a*q.a - b*q.b - c*q.c - d*q.d;
    i  = a*q.b + b*q.a + c*q.d - d*q.c;
    j  = a*q.c + c*q.a + d*q.b - b*q.d;
    k  = a*q.d + d*q.a + b*q.c - c*q.b;
    return Quat(t0, i, j, k);
}
bool Quat:: operator!=(const Quat& q) const{
    return a != q.a || b != q.b || c != q.c || d != q.d;
}

bool Quat:: operator==(const Quat& q) const {
    return a == q.a && b == q.b && c == q.c && d == q.d;
}
void Quat::operator=(const Quat& q){
    a = q.a;
    b = q.b;
    c = q.c;
    d = q.d;
}

void Quat::operator*=(float R)
{
    a*= R;
    b*= R;
    c*= R;
    d*= R;
}

void Quat::operator+=(Quat& q)
{
    a += q.a;
    b += q.b;
    c += q.c;
    d += q.d;
}

void Quat::operator-=(Quat& q)
{
    a -= q.a;
    b -= q.b;
    c -= q.c;
    d -= q.d;
}

void Quat::operator/=(float R)
{
    a /= R;
    b /= R;
    c /= R;
    d /= R;
    
}
Quat Quat::Inverse(){
    Quat q2 = Conjugate();
    float module = norm() * norm();
    return Quat(q2.a/module, q2.b/module, q2.c/module, q2.d/module);
}

Quat Quat::Rotation3d(Quat& axis, float angle)
{
    //Reduce axis vector in a vector of a unit lenght if it's not;
    float axisMagnitude = axis.norm();
    if (axisMagnitude != 1)
    {
        axis /= axisMagnitude;
    }
    float angletoRad = (angle * M_PI) / 180.0f;
    axis *= sin(angletoRad/2);
    Quat q = {cosf(angletoRad/2)};
    q += axis;
    Quat P_prime = q * (*this) * q.Inverse();
    return P_prime; // New vector after the rotation;
}

namespace PhysiX{
std::ostream& operator<<(std::ostream& os, const Quat& q) {
    auto signPrinter = [](float value, std::ostream& os){
        os << (value >= 0 ? " + " : " - ");
    };
    
    os << q.getA();
    signPrinter(q.getB(), os); os << fabs(q.getB()) << "i";
    signPrinter(q.getC(), os); os << fabs(q.getC()) << "j";
    signPrinter(q.getD(), os); os << fabs(q.getD()) << "k";
    
    return os;
}
}
