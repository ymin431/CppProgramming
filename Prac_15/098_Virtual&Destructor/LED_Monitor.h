#include "Monitor.h"

#ifndef __LEDMONITOR_H__
#define __LEDMONITOR_H__

class LED_Monitor : public Monitor {

public:
    LED_Monitor() : Monitor() {
        std::cout << "LED_Monitor constructor" << std::endl ;
    } ;
    ~LED_Monitor() override {
        std::cout << "LED_Monitor destructor" << std::endl ;
    } ;

};

#endif
