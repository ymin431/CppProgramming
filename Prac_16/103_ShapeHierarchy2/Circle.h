
#ifndef CIRCLE_H
#define CIRCLE_H

#include "IShape.h"
#include "Helper.h"
#include <cmath>
#include <sstream>
#include <iomanip>


class Circle : public IShape {
public:
    Circle(const Point& center, double radius) : center(center), radius(radius) {}
    ~Circle() {
        std::cout << "Circle destructor called" << std::endl ;
    }
    double getArea() const override {
        return M_PI * radius * radius ;
    }
    double getPerimeter() const override {
        return 2 * M_PI * radius ;
    }
    std::string toString() const override {
        std::ostringstream oss;
        oss << "Circle Area: " << std::fixed << std::setprecision(2) << getArea()
            << ", Perimeter: " << getPerimeter();
        return oss.str();
    }

private:
    Point center ;
    double radius ;
};

#endif //CIRCLE_H
