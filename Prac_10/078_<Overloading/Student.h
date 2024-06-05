#include <map>
#include <iostream>
#include <vector>
#include <algorithm>

class Student {

public:
    Student() ;
    Student(int _id, std::string _name, int _grade) ;
    friend bool compareByGrade(const Student& a, const Student& b) ;
    bool operator<(const Student& other) const ;
    friend std::ostream& operator<<(std::ostream& os, const Student& stu) ;

private:
    int id ;
    std::string name ;
    int grade ;

};

bool compareByGrade(const Student& a, const Student& b) ;

std::ostream& operator<<(std::ostream& os, const Student& stu) ;