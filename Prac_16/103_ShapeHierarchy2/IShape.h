#include <iostream>
#include <vector>

#ifndef ISHAPE_H
#define ISHAPE_H

class Point {
public:
    int x = 0;
    int y = 0;
    Point(int _x, int _y) : x(_x), y(_y) {};
};

class IShape {
public:
    IShape() = default;
    virtual ~IShape() noexcept {
        std::cout << "IShape destructor called" << std::endl;
    };
    IShape(const std::vector<Point>& points) : points(points) {};;
    virtual double getArea() const = 0;
    virtual double getPerimeter() const = 0;

    friend std::ostream& operator<<(std::ostream& str, const IShape& shape);

protected:
    virtual std::string toString() const = 0;
    std::vector<Point> points;
};

std::ostream& operator << (std::ostream& os, const IShape& shape) {
    return os << shape.toString();
}

#endif //ISHAPE_H
