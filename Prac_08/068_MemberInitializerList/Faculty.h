#include <iostream>

#ifndef FACULTY_H
#define FACULTY_H

#include "University.h"
#include "Department.h"

class Faculty {

public:
    Faculty(std::string name, int members) : name(name), members(members) {} ;
//    Faculty() : name("N/A"), members(0) {} ;
    std::string getName() {
        return this->name ;
    }
    int getMem() {
        return this->members ;
    }

private:
    std::string name ;
    int members ;

};

#endif