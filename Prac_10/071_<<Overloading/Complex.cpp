#include "Complex.h"
#include <iostream>

std::ostream& operator << (std::ostream& os, const Complex& c) {
    return os << c.r << "+" << c.i << "i";
}