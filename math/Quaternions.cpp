#include <iostream>
#include "Quaternions.h"

using namespace std;

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
std::ostream& operator<<(std::ostream& os, const Quat& q) {
    auto signPrinter = [](float value, std::ostream& os){
        os << (value >= 0 ? " + " : " - ");
    };
    
    os << q.a;
    signPrinter(q.b, os); os << abs(q.b) << "i";
    signPrinter(q.c, os); os << abs(q.c) << "j";
    signPrinter(q.d, os); os << abs(q.d) << "k";
    
    return os;
}