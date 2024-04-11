#include <iostream>
#include <cmath>

class Point {

  public:
    // implements the constructor with member initializer list
    Point(double x=0, double y=0) ;
    double norm() const ; // sqrt(x*x + y*y)
    double getX() const ;
    double getY() const ;

  private:
    const double x, y ;

};