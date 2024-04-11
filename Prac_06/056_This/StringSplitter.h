#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>

class StringSplitter {

    public:
        StringSplitter( std::string str ) ;
        StringSplitter& trim() ;
        StringSplitter& removeNonAlnum() ;
        std::vector<std::string> split( char ch ) ;

    private:
        std::string line ;

};