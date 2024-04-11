#include <iostream>
#include <vector>

int main( ) {

  int len, sum = 0 ;
  std::cin >> len ;

  std::vector<int> vec(len) ;

  for ( int i = 0; i < len; i++)
    std::cin >> vec[i];

  for ( int i : vec ) 
    sum += i ;


  std::cout << sum << std::endl ;

  

  return 0 ;

}