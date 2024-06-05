#include "Printer.h"

#ifndef __LEDMONITOR_H__
#define __LEDMONITOR_H__

class LED_Monitor : Monitor {

public:
    LED_Monitor() : Monitor() {
        std::cout << "LED_Monitor constructor" << std::endl ;
    } ;
    ~LED_Monitor() {
        std::cout << "LED_Monitor destructor" << std::endl ;
    } ;

};

#endif
