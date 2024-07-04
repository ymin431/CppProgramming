#include <iostream>
#include "Array.h"

int main() {
    try {
        Array<int> arr(5);
        arr.at(0) = 1;
        arr.at(1) = 2;
        arr.at(2) = 3;
        arr.at(3) = 4;
        arr.at(4) = 5;
        arr.at(5) = 6;
    } catch (const std::out_of_range& error) {
        std::cerr << "Out of Range error: " << error.what() << std::endl ;
    }
    return 0;
}