#include <iostream>

void println( const std::string& str );

int main( ) {

  std::string str = "hello, world!" ;

  println( str ) ;

  for ( int i = 0 ; i < 3 ; i++ )
    println( str ) ;

  return 0 ;

}

void println( const std::string& str ) { 

  std::cout << str << "\n";

}