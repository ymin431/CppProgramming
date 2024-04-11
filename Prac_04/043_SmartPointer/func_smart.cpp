#include <iostream>
#include <vector>
#include "student.h"

int main( ) {

  int num, age ;
  std::string name ;

  std::cin >> num ;

  std::vector<STUDENT> vec( num ) ;
  std::unique_ptr<STUDENT> ptr ;

  for ( int i = 0 ; i < num ; i++ ) {
    
    std::cin >> name >> age ;
    ptr = createStudent( name, age ) ; 
    vec[i] = *ptr ;

  }

  for ( auto i : vec ) 
    printStudentInfo( i ) ;

  return 0 ;

}