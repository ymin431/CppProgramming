#include "shape.cpp"

int main() {

    std::string func ;

    while ( std::cin >> func ) {

        if ( func == "RECT"  ) { // Rectangle 생성

            Point pos1, pos2 ;
            std::cin >> pos1.x >> pos1.y >> pos2.x >> pos2.y ;
            create_rectangle(pos1, pos2) ;

        }
        else if ( func  == "CIRCLE" ) {

            Point center ;
            int radius ;
            std::cin >> center.x >> center.y >> radius ;
            create_circle(center, radius) ;

        }

    }

    for ( auto i : shape_list)
        std::cout << i.id << std::endl ;

    return 0 ;

}