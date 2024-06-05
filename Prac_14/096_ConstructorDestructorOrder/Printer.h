#include "Monitor.h"

#ifndef __PRINTER_H__
#define __PRINTER_H__

class Printer : OutputDevice {

public:
    Printer() : OutputDevice() {
        std::cout << "Printer constructor" << std::endl ;
    } ;
    ~Printer() {
        std::cout << "Printer destructor" << std::endl ;
    } ;

};

#endif