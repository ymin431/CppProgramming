#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>

enum SCALE {
    CELSIUS,
    FAHRENHEIT
};

class Temperature {
public:
    Temperature(double temp, SCALE scale=CELSIUS) ;
    Temperature add(Temperature other);
    std::string print() const;
private:
    // Conversion Function
    void convertToCelsius();
    void convertToFahrenheit();
private:
    double temperature;
    SCALE scale;
};
