#include <iostream>
#include <cmath>
#define PI  3.14

using namespace std;

class Geom {
protected:
    int type;
public:
    enum {RECT, CIRCLE, SQUARE, POINT};
    Geom(int t): type(t) {}
    Geom() {}
    virtual bool overlap(Geom* geom) = 0;

    int getType() const { return type; }
};

class Point: public Geom {
    float   a, b;
public:
    Point(float x, float y): Geom(POINT), a(x), b(y) {}
    Point() : Geom(POINT), a(0), b(0) {}

    float getX() const { return a; }
    float getY() const { return b; }

    bool overlap(Geom* geom) override {
        // Point와 다른 도형과의 겹침 여부를 구현합니다.
        // 여기서는 겹치지 않는 것으로 가정합니다.
        return false;
    }
};

class Circle: public Geom {
    Point   center;
    float   radius;
public:
    Circle(float x, float y, float r):
            Geom(CIRCLE), center(x,y), radius(r) {}
    Circle() : Geom(CIRCLE) {}

    Point getCenter() const { return center; }
    float getRadius() const { return radius; }

    bool overlap(Geom* geom) override {
        // Circle과 다른 도형과의 겹침 여부를 구현합니다.
        // 여기서는 겹치지 않는 것으로 가정합니다.
        return false;
    }
};

class Rectangle: public Geom {
    Point   p1; // bottom left corner point
    Point   p2; // top right corner point
public:
    Rectangle(float x1, float y1, float x2, float y2) :
            Geom(RECT), p1(x1,y1), p2(x2,y2) {}
    Rectangle() : Geom(RECT) {}

    Point getP1() const { return p1; }
    Point getP2() const { return p2; }

    bool overlap(Geom* geom) override {
        // Rectangle과 다른 도형과의 겹침 여부를 구현합니다.
        // 여기서는 겹치지 않는 것으로 가정합니다.
        return false;
    }
};

class Square: public Geom {
    Point   p;    // bottom left corner point
    float   side; // side length
public:
    Square(float x, float y, float _side) : Geom(SQUARE), p(x,y), side(_side) {}
    Square() : Geom(SQUARE) {}

    Point getP() const { return p; }
    float getSide() const { return side; }

    bool overlap(Geom* geom) override {
        // Square와 다른 도형과의 겹침 여부를 구현합니다.
        // 여기서는 겹치지 않는 것으로 가정합니다.
        return false;
    }
};

int main() {
    int numGeom;
    cin >> numGeom;
    Geom** geoms = new Geom*[numGeom];

    for (int i = 0; i < numGeom; i++) {
        string option;
        cin >> option;

        if (option == "R") {
            float x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            geoms[i] = new Rectangle(x1, y1, x2, y2);
        } else if (option == "S") {
            float x, y, side;
            cin >> x >> y >> side;
            geoms[i] = new Square(x, y, side);
        } else if (option == "C") {
            float x, y, r;
            cin >> x >> y >> r;
            geoms[i] = new Circle(x, y, r);
        }
    }

    // 코드 추가: 각 도형의 겹침 여부를 확인하고 결과를 출력합니다.
    int overlapCount = 0;
    for (int i = 0; i < numGeom; i++) {
        for (int j = i + 1; j < numGeom; j++) {
            if (geoms[i]->overlap(geoms[j])) {
                overlapCount++;
            }
        }
    }

    cout << "Number of overlaps: " << overlapCount << endl;

    // Clean up memory
    for (int i = 0; i < numGeom; i++) {
        delete geoms[i];
    }
    delete[] geoms;

    return 0;
}
