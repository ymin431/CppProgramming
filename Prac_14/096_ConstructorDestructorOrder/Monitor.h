#include "OutputDevice.h"

#ifndef __MONITOR_H__
#define __MONITOR_H__


class Monitor : OutputDevice {

public:
    Monitor() : OutputDevice() {
        std::cout << "Monitor constructor" << std::endl ;
    } ;
    ~Monitor() {
        std::cout << "Monitor destructor" << std::endl ;
    } ;

};

#endif