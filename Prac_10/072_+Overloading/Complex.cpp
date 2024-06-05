#include "Complex.h"
#include <iostream>

Complex Complex::operator + (const Complex rhs) {
    return Complex(this->r + rhs.r, this->i + rhs.i) ;
}

Complex Complex::operator - (const Complex rhs) {
    return Complex(this->r - rhs.r, this->i - rhs.i) ;
}

std::ostream& operator << (std::ostream& os, const Complex& c) {
    return os << c.r << "+" << c.i << "i";
}