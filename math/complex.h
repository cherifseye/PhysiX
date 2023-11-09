#pragma once
#include "Quaternions.h"

class Complex : public Quat {
public:

    Complex(float a = 0, float b = 0);
    Complex(const Quat& q) : Quat(q.getA(), q.getB()) {};
    void operator=(const Complex& c);
    Complex operator+(const Complex& c);
    Complex operator-(const Complex& c);
    Complex operator*(const Complex& c);
    Complex operator/(const Complex& c);
    Complex conjugate() const;
    bool operator==(const Complex& c);
    bool operator!=(const Complex& c);
    float argument();
    float module();
    friend std::ostream& operator<<(std::ostream& os, const Complex& c);

};