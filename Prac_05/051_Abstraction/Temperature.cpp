#include "Temperature.h"

std::string Temperature::print() const {
    std::stringstream ss;
    ss << std::fixed;
    ss << std::setprecision(1);
    if (this->scale == FAHRENHEIT) {
        ss << this->temperature << " F\n";
    } else {
        ss << this->temperature << " C\n";
    }
    return ss.str();
}


void Temperature::convertToCelsius() {

  this->scale = CELSIUS ;
  this->temperature = ( this->temperature - 32 ) * 5/9 ;

}

void Temperature::convertToFahrenheit() { 

  this->scale = FAHRENHEIT ;
  this->temperature = ( this->temperature * 9/5 ) + 32 ;

}

Temperature::Temperature(double temp, SCALE scale) : temperature(temp), scale(scale) { } ; 

Temperature Temperature::add( Temperature other ) {

  if ( this->scale != other.scale && this->scale == FAHRENHEIT ) 
    other.convertToFahrenheit() ;
  
  else if ( this->scale != other.scale && this->scale == CELSIUS )
    other.convertToCelsius() ;

  return Temperature ( this->temperature + other.temperature, this->scale ) ;

}