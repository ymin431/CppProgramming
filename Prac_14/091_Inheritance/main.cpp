#include <iostream>
#include <string>
using namespace std;

class Person {

public:
    Person(string name) : name(name) {
        cout << "Person is constructed!" << endl ;
    } ;
    ~Person() {
        cout << "Person is destructed!" << endl ;
    }
    string getName() const {
        return this->name ;
    }
    void print() const {
        cout << "Person Name: " << getName() << endl ;
    } ;

private:
    string name ;

};

class Student : public Person {

public:
    Student(string name, string schoolName) : Person(name), schoolName(schoolName) {
        cout << "Student is constructed!" << endl ;
    } ;
    ~Student() {
        cout << "Student is destructed!" << endl ;
    } ;
    string getSchoolName() const {
        return this->schoolName ;
    };
    void print() const {
        cout << "Person Name: " << getName() << endl ;
        cout << "School Name: " << getSchoolName() << endl ;
    } ;

private:
    string name ;
    string schoolName ;

};

int main() {
    Person p1{"Park"};
    p1.print();

    Student s1 {"Kim", "PNU"};
    s1.print();

    return 0;
}