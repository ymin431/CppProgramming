#include "String.h"
#include <cstring>
#include <iostream>
#include <algorithm>
#include <numeric>

String::String() {
    s = new char[1] ;
    s[0] = '\0' ;
    len = 0 ;
}

String::String(const char *str) {
    len = strlen(str) ;
    s = new char[len+1] ;
    std::copy(str,str+len+1,s) ;
}

String::String(const String &str) {
    len = str.len ;
    s = new char[len + 1] ;
    std::copy(str.s, str.s+len+1,s) ;
}

String::~String() {
    delete[] s ;
}

String& String::operator=(const String& str) {
    if (this != &str) {
        len = str.len ;
        s = new char[len + 1] ;
        std::copy(str.s, str.s + len + 1, s) ;
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
    std::cout << str << ": " << this->data() << ", size: " << this->size() << std::endl ;
}

void printString(const char *str) {
    std::cout << "printString" << ": " << str << ", "
              << "size: " << sizeof(str) << std::endl;
}