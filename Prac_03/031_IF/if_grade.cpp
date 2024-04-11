#include <iostream>

int main( ) {

  int grade ;

  std::cin >> grade ;

  if ( 90 <= grade && grade <= 100 )
    std::cout << "A" << std::endl ;

  else if ( 80 <= grade && grade <= 89 )
    std::cout << "B" << std::endl ;

  else if ( 70 <= grade && grade <= 79 )
    std::cout << "C" << std::endl ;

  else if ( 60 <= grade && grade <= 69 )
    std::cout << "D" << std::endl ;

  else
    std::cout << "F" << std::endl ;

  return 0 ;

}