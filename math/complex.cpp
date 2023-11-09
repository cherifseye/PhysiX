#include "complex.h"
#include <cmath>
#include <iostream>

Complex::Complex(float a, float b) : Quat(a, b) {}
Complex  Complex:: operator+(const Complex& c){
    return Complex(a + c.a, b+c.b);
}
Complex Complex::operator-(const Complex& c){
    return Complex(a - c.a, b - c.b);
}
Complex Complex:: operator*(const Complex& c){
    float newA = a * c.a - b*c.b;
    float newB = a*c.a + b * c.a;
    return Complex(newA, newB);

}
Complex Complex::operator/(const Complex& c){
    if (c.a != 0 || c.b != 0) { // updated the condition
        Complex numerator = *this * c.conjugate();
        float denominator = c.a * c.a + c.b * c.b;
        return Complex(numerator.a / denominator, numerator.b / denominator);
    } else {
        throw std::invalid_argument("Division by zero is not allowed."); // Handling zero denominator
    }
}
Complex Complex ::conjugate() const{
    return Complex(a, -b);
}

void Complex::operator=(const Complex& c){
    a = c.a;
    b = c.b;
}

bool Complex:: operator==(const Complex& c){
    return (a == c.a && b == c.b);
}

bool Complex:: operator!=(const Complex& c){
    return (a != c.a || b!= c.b);
}
float Complex::argument() {
    if (a == 0 && b == 0) {
        return 0; 
    } 
    return atan2(b, a);
}


float Complex:: module(){
    return sqrt(pow(a, 2) + pow(b, 2));
}

std::ostream& operator<<(std::ostream& os, const Complex& c) {
    os << c.a; 
    if (c.b == 0){
        return os;
    }else{
        os<< (c.b >= 0 ? " + " : " - ");
        if (c.b != 1) os <<abs(c.b);
    }
    os << "i";
    return os;
}

