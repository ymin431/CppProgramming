#include "StringSplitter.h"

StringSplitter::StringSplitter( std::string str ) : line(str) {} ;

StringSplitter& StringSplitter::trim() {
    this->line.erase(0, this->line.find_first_not_of(" ")) ;
    this->line.erase(this->line.find_last_not_of(" ")+1) ;
    return *this ;
} ;

StringSplitter& StringSplitter::removeNonAlnum() {
    this->line.erase(std::remove_if(this->line.begin(), this->line.end(),
                                    [](char a){return !isalnum(a) && !isspace(a);}), this->line.end()) ;
    return *this ;
} ;

std::vector<std::string> StringSplitter::split( char ch ) {
    std::vector<std::string> split_vec ;
    std::string tmp ;
    std::stringstream stream(this->line) ;
    while ( getline(stream, tmp, ch) )
//    while ( stream >> tmp )
        split_vec.push_back(tmp) ;
    return split_vec ;
} ;
