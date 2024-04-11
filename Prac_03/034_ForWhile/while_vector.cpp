#include <iostream>
#include <vector>
#include <climits>

int main( ) {

  int num ;
  std::vector<int> vec ;

  while ( std::cin >> num ) 
    vec.push_back(num) ;

  int N = 0 ;
  int min = INT_MAX ;
  int max = INT_MIN ;

  for( int i : vec ) {

    N += 1 ;

    if ( i < min )
      min = i ;

    if ( i > max )
      max = i ;

  }

  std::cout << N << " " << min << " " << max << std::endl;

  return 0 ; 

}