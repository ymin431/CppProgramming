#include <iostream>
#include "data.cpp"
#include "reader.cpp"
#include "sum.cpp"

extern std::vector<int> vec ;
extern int total ;

void read( ) ;
void sum( ) ;

int main( ) {

    read( ) ;
    sum( ) ;
    std::cout << total << std::endl ;
    return 0 ;

}