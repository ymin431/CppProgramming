#include "Rectangle.h"

Rectangle::Rectangle( double x1, double y1, double x2, double y2 ) : leftTop(x1,y1), rightBottom(x2,y2) {} ;

double Rectangle::area() const {

  double xchange = this->rightBottom.getX() - this->leftTop.getX() ;
  double ychange = this->leftTop.getY() - this->rightBottom.getY() ;

  double area = xchange * ychange ;

  return abs(area) ;

} ;