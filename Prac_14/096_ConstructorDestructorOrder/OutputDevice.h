#include <iostream>

#ifndef __OUTPUTDEVICE_H__
#define __OUTPUTDEVICE_H__

class OutputDevice {

public:
    OutputDevice() {
        std::cout << "OutputDevice constructor" << std::endl ;
    } ;
    ~OutputDevice() {
        std::cout << "OutputDevice destructor" << std::endl ;
    } ;

};

#endif