#include <iostream>

enum Choice { ROCK, PAPER, SCISSORS } ;

int main( ) {

  int player, computer ;

  std:: cin >> player >> computer ;

  switch ( player ) {
 
    case ROCK :
      std::cout << "You chose rock." << std::endl ;
      break;
    
    case PAPER :
      std::cout << "You chose paper." << std::endl ;
      break;

    case SCISSORS :
      std::cout << "You chose scissors." << std::endl ;

  }

  switch ( computer ) {
 
    case ROCK :
      std::cout << "The computer chose rock." << std::endl ;
      break;
    
    case PAPER :
      std::cout << "The computer chose paper." << std::endl ;
      break;

    case SCISSORS :
      std::cout << "The computer chose scissors." << std::endl ;

  }

  if ( player == computer ) 
    std::cout << "You tied!" << std::endl ;

  else if ( ( player + 1 ) % 3 == computer )
    std::cout << "The computer won!" << std::endl ;

  else
    std::cout << "You won!" << std::endl ;

  return 0 ;

}