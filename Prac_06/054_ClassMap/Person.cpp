#include "Person.h"

Person::Person(std::string name, std::string number) : name(name), number(number) {} ;

void Person::modifyNumber(std::string number) {

    this->number = number ;

}

void Person::print() const {

    std::cout << this->name << " " << this->number << std::endl ;

}