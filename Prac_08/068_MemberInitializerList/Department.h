#include <iostream>
//#include "Faculty.h"

class Department {

public:
    Department(std::string name) : name(name) {} ;
    Department() {} ;

private:
    std::string name;
    Faculty* faculty;

};