
#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "IShape.h"
#include "Helper.h"
#include <sstream>
#include <iomanip>

class Rectangle : public IShape {
public:
    Rectangle(const std::vector<Point>& points) : IShape(points) {}
    ~Rectangle() {
        std::cout << "Rectangle destructor called" << std::endl ;
    }
    double getArea() const override {
        double width = calcDist(points[0], points[1]);
        double height = calcDist(points[1], points[2]);
        return width * height;
    }
    double getPerimeter() const override {
        double width = calcDist(points[0], points[1]);
        double height = calcDist(points[1], points[2]);
        return 2 * (width + height);
    }
    std::string toString() const override {
        std::ostringstream oss;
        oss << "Rectangle Area: " << std::fixed << std::setprecision(2) << getArea()
            << ", Perimeter: " << getPerimeter();
        return oss.str();
    }
};

#endif //RECTANGLE_H
