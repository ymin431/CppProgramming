 #include "Array.h"
#include <iostream>

Array::Array(std::initializer_list<int> args, size_t size) : data(new int[size]), _size(size) {

    if ( args.size() != size )
        std::cout << "Invalid Size" << std::endl ;

    std::copy(args.begin(), args.end(), data.get()) ;

}

int &Array::operator[](int index) {

    return data[index] ;

}

size_t Array::size() const {

    return _size ;

}