#include "String.h"
#include <iostream>
#include <cstring>

String::String() {
    s = new char[1];
    s[0] = '\0';
    len = 0 ;
}

String::String(const char *str) {
    if(str) {
        len = strlen(str) ;
        s = new char[strlen(str) + 1];
        strcpy(s, str);
    } else {
        len = 0 ;
        s = new char[1];
        s[0] = '\0';
    }
}

String::String(const String &str) {
    std::cout << str.s << std::endl ;
    if ( strcmp(str.data(), this->data()) != 0 ) {
        len = str.len ;
        s = new char[len + 1] ;
        strcpy(s, str.s) ;
    }
    else {
        len = 0 ;
        s = new char[1] ;
        s[0] = '\0' ;
    }
}

String::~String() {
    delete[] s ;
}

String& String::operator=(const String& str) {
    std::cout << "=" << std::endl ;
    if (this != &str) {
        delete[] s;
        len = str.len;
        s = new char[len + 1];
        strcpy(s, str.s);
    }
    return *this;
}

const char *String::data() const {
    return s ;
}

char &String::at(size_t index) {
    return  s[index] ;
}

size_t String::size() const {
    return len ;
}

void String::print(const char *str) const {
    std::cout << str << ": " << this->s << ", size: " << this->len << std::endl ;
}
void String::print(const char *str) const {
    std::cout << str << ": " << this->s << ", size: " << this->len << std::endl ;
}