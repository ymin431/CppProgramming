#include <iostream>
#include <map>

long long numID = 1 ;

class Person {
    public:
        Person(std::string name, size_t age) : name{name}, age{age} {
            ID = numID ;
            numID++ ;
        };

        friend std::ostream& operator << (std::ostream& out, const Person& p) {
            return out << p.ID << " " << p.name << " " << p.age ;
        };

        bool operator < (const Person& rhs) const {
            return this->ID < rhs.ID ;
        };

        class ComparatorByAge {
            public:
                bool operator()(const Person& lhs, const Person& rhs) const{
                    return lhs.age < rhs.age ;
                }
        };

        class ComparatorByName {
            public:
                bool operator()(const Person& lhs, const Person& rhs) const {
                    return lhs.name < rhs.name ;
                }
        };

    private:
        long long ID;
        std::string name;
        size_t age;
};
