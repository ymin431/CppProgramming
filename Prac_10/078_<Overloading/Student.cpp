#include "Student.h"

Student::Student() {}

Student::Student(int _id, std::string _name, int _grade) {
    id = _id ;
    name = _name ;
    grade = _grade ;
}

bool compareByGrade(const Student& a, const Student& b) {
    return b.grade < a.grade ;
}

bool Student::operator<(const Student &other) const {
    return this->name < other.name ;
}

std::ostream& operator<<(std::ostream& os, const Student& stu) {
    return os << "Id: " << stu.id << " Name: " << stu.name << " Grade: " << stu.grade ;
}