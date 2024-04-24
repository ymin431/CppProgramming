#include <iostream>
#include <vector>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 640;

enum class ShapeType {
    RECT,
    CIRCLE
};

struct Point {
    int x;
    int y;
};

struct Shape {
    int id;
    ShapeType type;
    Point pos1;
    Point pos2;
    Point center;
    int radius;
    double area ; // 내가 추가함
};

void create_rectangle(Point& pos1, Point& pos2);
void create_circle(Point& center, int radius);
void move_shape(int id, int x, int y);
void sort_shapes();
int find_furthest_shape();
void remove_shape_by_id(int id);
void align_shapes();
void print_shapes();
