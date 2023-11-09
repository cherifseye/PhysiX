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
    void rotation2D(float angle);
    void operator+=(Complex& c);
    void operator-=(Complex& c);
    void operator*=(float R);
    void operator/=(float R);
    bool operator==(const Complex& c) const;
    bool operator!=(const Complex& c) const;
    float argument();
    float module();
    friend std::ostream& operator<<(std::ostream& os, const Complex& c);

};