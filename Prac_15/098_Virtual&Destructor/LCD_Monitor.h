#include "LED_Monitor.h"

#ifndef __LCDMONITOR_H__
#define __LCDMONITOR_H__

class LCD_Monitor : public Monitor {

public:
    LCD_Monitor() : Monitor() {
        std::cout << "LCD_Monitor constructor" << std::endl ;
    } ;
    ~LCD_Monitor() override {
        std::cout << "LCD_Monitor destructor" << std::endl ;
    } ;

};

#endif