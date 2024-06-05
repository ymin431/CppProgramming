#include <iostream>

#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include "University.h"
#include "Faculty.h"

class Department {

public:
    Department(std::string name, Faculty* faculty) : name(name), faculty(faculty) {} ;
    Department(std::string name) : name(name), faculty() {} ;
    void setFaculty(Faculty* faculty) {
        this->faculty = faculty ;
    } ;
    std::string getDeptName() {
        return this->name ;
    }
    Faculty* getFac() {
        return this->faculty ;
    }

private:
    std::string name;
    Faculty* faculty;

};

#endif