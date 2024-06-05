#include "LCD_Monitor.h"

int main() {
    {
        Monitor monitor;
        //monitor.print();
    }
    std::cout << "--------------------------" << std::endl;
    {
        Monitor* pMonitor = new LED_Monitor();
        if (pMonitor) delete pMonitor;
    }
    std::cout << "--------------------------" << std::endl;
    {
        std::unique_ptr<OutputDevice> pMonitor = std::make_unique<LCD_Monitor>();
    }
}