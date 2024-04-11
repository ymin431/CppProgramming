#include "Point.h"

Point::Point( double x, double y ) : x(x), y(y) {} ;

double Point::norm() const { return sqrt(x*x + y*y); } ;

double Point::getX() const { return this->x; } ;

double Point::getY() const { return this->y; } ;