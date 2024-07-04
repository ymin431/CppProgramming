#ifndef POLYGON_H
#define POLYGON_H

#include "IShape.h"
#include "Helper.h"
#include <cmath>
#include <sstream>
#include <iomanip>

class Polygon : public IShape {
public:
    Polygon(const std::vector<Point>& points) : IShape(points) {}
    ~Polygon() noexcept override {
        std::cout << "Polygon destructor called" << std::endl;
    }
    double getArea() const override {
        double area = 0.0;
        int n = points.size();
        for (int i = 0; i < n; ++i) {
            int j = (i + 1) % n;
            area += points[i].x * points[j].y;
            area -= points[i].y * points[j].x;
        }
        area = std::fabs(area) / 2.0;
        return area;
    }
    double getPerimeter() const override {
        double perimeter = 0.0;
        int n = points.size();
        for (int i = 0; i < n; ++i) {
            int j = (i + 1) % n;
            perimeter += calcDist(points[i], points[j]);
        }
        return perimeter;
    }
    std::string toString() const override {
        std::ostringstream oss;
        oss << "Polygon Area: " << std::fixed << std::setprecision(2) << getArea()
            << ", Perimeter: " << getPerimeter();
        return oss.str();
    }
};

#endif // POLYGON_H
