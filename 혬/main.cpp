#include <iostream>
#define PI  3.14

using namespace std;


class Geom {
protected:
    int type;
public:
    enum {RECT, CIRCLE, SQUARE, POINT};
    Geom(int t): type(t) {}
    Geom() {}
    virtual bool overlap()=0;

    int getType() const { return type; }
};

class Point: public Geom {
    float   a, b;
public:
    Point(float x, float y): Geom(POINT), a(x), b(y) {}
    Point() {}

    float getX() const { return a; }
    float getY() const { return b; }
};

class Circle: public Geom {
    Point   center;
    float   radius;
public:
    Circle(float x, float y, float r):
            Geom(CIRCLE), center(x,y), radius(r) {}
    Circle() {}

    Point getCenter() const { return center; }
    float getRadius() const { return radius; }

    bool overlap(Circle c) override {
        for (int i = 0; i < numGeom; i++) {
            if (geom[i]->getType() == CIRCLE) {
                float dx = pow(this->center - geom[i].)
            }

            else if (geom[i]->getType() == RECT) {
            }

            else if (geom[i]->getType() == SQUARE) {

            }
        }
    }
};

class Rectangle: public Geom {
    Point   p1; // bottom left corner point
    Point   p2; // top right corner point
public:
    Rectangle(float x1, float y1, float x2, float y2) :
            Geom(RECT), p1(x1,y1), p2(x2,y2) {}
    Rectangle() {}

    Point getP1() const { return p1; }
    Point getP2() const { return p2; }

    bool overlap(Geom** geom, int numGeom) override {
        for (int i = 0; i < numGeom; i++) {
            if (geom[i]->getType() == CIRCLE) {

            }

            else if (geom[i]->getType() == RECT) {

            }

            else if (geom[i]->getType() == SQUARE) {

            }
        }
    }
};

class Square: public Geom {
    Point   p;    // bottom left corner point
    float   side; // side length
public:
    Square(float x, float y, float _side) : Geom(SQUARE), p(x,y), side(_side) {}
    Square() {}

    Point getP() const { return p; }
    float getSide() const { return side; }

    bool overlap(Geom** geom, int numGeom) override {
        for (int i = 0; i < numGeom; i++) {
            if (geom[i]->getType() == CIRCLE) {

            }

            else if (geom[i]->getType() == RECT) {

            }

            else if (geom[i]->getType() == SQUARE) {

            }
        }
    }
};


int main()
{
    int     numGeom;
    cin>> numGeom;
    Geom** geoms = new Geom*[numGeom+1] ;

    for(int i=0;i<numGeom + 1;i++) {

        string option ;
        cin >> option ;

        if (option == "R") {
            float x1, y1, x2, y2 ;
            cin >> x1 >> y1 >> x2 >> y2 ;
            geoms[i] = new Rectangle(x1, y1, x2, y2) ;
        }

        else if (option == "S") {
            float x, y, side ;
            cin >> x >> y >> side ;
            geoms[i] = new Square(x, y, side) ;
        }

        else if (option == "C") {
            float x, y, r ;
            cin >> x >> y >> r ;
            geoms[i] = new Circle(x, y, r) ;
        }

    }

    for (int i = 0; i < numGeom; i++) {

//        enum {RECT, CIRCLE, SQUARE, POINT};
        if (geoms[i]->getType() == 0) {
            Rectangle *a = dynamic_cast<Rectangle *>(geoms[i]);
            a->overlap() ;
        }
        else if (geoms[i]->getType() == 1) {
            Circle *a = dynamic_cast<Circle *>(geoms[i]);
        }
        else {
            Square *a = dynamic_cast<Square *>(geoms[i]);
        }

    }

//    geoms[numGeom + 1]->overlap(geoms, numGeom) ;


    return 0;
}
