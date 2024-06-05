#include <iostream>

using namespace std ;

class Employee {
public:
    Employee(string name, int salary) : name_(name), salary_(salary) {}
    virtual void print_report() const {
        cout << "Name: " << name_ << endl;
        cout << "Salary: " << salary_ << endl;
        cout << "Years of service: " << years_of_service_ << endl;
        cout << "Performance score: " << performance_score_ << endl;
    }
    string get_name() const {
        return name_;
    }
    virtual ~Employee() = default ;

protected:
    string name_;
    int salary_;
    int years_of_service_ = 0;
    int performance_score_ = 0;
};

class Manager : public Employee {

public:
        Manager(string name, int salary, string dept) :
                Employee(name, salary), dept(dept) {}
        void set_goals() {
            cout << "Set goals for " << dept << endl ;
        }
        void print_report() const override {
            Employee::print_report();
            cout << "Department: " << dept << endl ;
        }

protected:
    string dept ;

};

class Programmer : public Employee {

public:
    Programmer(string name, int salary, string lang) :
            Employee(name, salary), lang(lang) {}
    void write_code() {
        cout << "Writing code in " << lang << endl ;
        performance_score_ += 10 ;
    }
    void print_report() const override {
        Employee::print_report() ;
        cout << "Language: " << lang << endl ;
    }

protected:
    string lang ;

};

class Salesperson : public Employee {

public:
    Salesperson(string name, int salary, int sales) :
            Employee(name, salary), sales(sales) {}
    void sell() {
        cout << "Selling products, generated " << sales << " in revenue" << endl ;
        performance_score_ += 20 ;
    }
    void print_report() const override {
        Employee::print_report() ;
        cout << "Sales: " << sales << endl ;
    }

protected:
    int sales ;

};