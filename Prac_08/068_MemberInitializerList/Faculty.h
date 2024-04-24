#include <iostream>
//#include "Department.h"

class Faculty {

public:
    Faculty(std::string name, int numDepartments) : name(name), numDepartments(numDepartments) {} ;


private:
    std::string name;
    int numDepartments;
    Department* departments;


};