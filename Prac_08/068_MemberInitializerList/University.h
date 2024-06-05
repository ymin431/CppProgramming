#include <iostream>
#include <algorithm>

#ifndef UNIVERSITY_H
#define UNIVERSITY_H

#include "Department.h"
#include "Faculty.h"

class University {

public:
    University(const std::string& name, int num) : name(name), ndept(num) {} ;
    void setDepartments(Department* department) {
        this->departments = department ;
    }
    void printInfo() {
        std::cout << "University Name: " << this->name << std::endl ;
        std::cout << "Number of Departments: " << this->ndept << std::endl ;
        std::cout << std::endl ;

        std::for_each(departments, departments + ndept, [](Department& i){
            std::cout << "Department Name: " << i.getDeptName() << std::endl ;

            if ( i.getFac() == nullptr ) {
                std::cout << "Faculty Name: N/A" << std::endl ;
                std::cout << "Number of Faculty Members: N/A" << std::endl ;
            }

            else {
                std::cout << "Faculty Name: " << i.getFac()->getName() << std::endl ;
                std::cout << "Number of Faculty Members: " << i.getFac()->getMem() << std::endl ;
            }

            std::cout << std::endl ;
        });
    }

private:
    std::string name;
    int ndept;
    Department* departments;

};

#endif