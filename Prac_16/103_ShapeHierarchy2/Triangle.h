
#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "IShape.h"
#include "Helper.h"
#include <sstream>
#include <iomanip>


class Triangle : public IShape {
public:
    Triangle(const std::vector<Point>& points) : IShape(points) {}
    ~Triangle() {
        std::cout << "Triangle destructor called" << std::endl ;
    }
    double getArea() const override {
        double a = calcDist(points[0], points[1]);
        double b = calcDist(points[1], points[2]);
        double c = calcDist(points[2], points[0]);
        double s = (a + b + c) / 2;
        return std::sqrt(s * (s - a) * (s - b) * (s - c));
    }
    double getPerimeter() const override {
        double a = calcDist(points[0], points[1]);
        double b = calcDist(points[1], points[2]);
        double c = calcDist(points[2], points[0]);
        return a + b + c;
    }
    std::string toString() const override {
        std::ostringstream oss;
        oss << "Triangle Area: " << std::fixed << std::setprecision(2) << getArea()
            << ", Perimeter: " << getPerimeter();
        return oss.str();
    }
};

#endif //TRIANGLE_H
