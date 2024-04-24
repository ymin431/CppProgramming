#include "shape.h"

std::vector<Shape> shape_list ;
int next_id = 0 ;

void create_rectangle( Point& pos1, Point& pos2 ) {

    Shape shape ;

    shape.id = next_id ;
    next_id++ ;

    shape.type = ShapeType::RECT ;

    shape.pos1 = pos1 ;
    shape.pos2 = pos2 ;

    shape_list.push_back(shape) ;

}

void create_circle( Point& center, int radius ) {

    Shape shape ;

    shape.id = next_id ;
    next_id++ ;

    shape.type = ShapeType::CIRCLE ;

    shape.center = center ;

    shape.radius = radius ;

    shape_list.push_back(shape) ;

}

void move_shape(int id, int x, int y) {

}

void sort_shapes() {

    std::sort(shape_list.begin(), shape_list.end(), [](Shape& a, Shape&b){return a.})

}

int find_furthest_shape() {

}

void remove_shape_by_id(int id) {

}

void align_shapes() {

}

void print_shapes() {

}