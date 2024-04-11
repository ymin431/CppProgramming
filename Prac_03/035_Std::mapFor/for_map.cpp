#include <iostream>
#include <map> 

int main( ) {

  int num ;

  std::cin >> num ;

  std::map<std::string, std::string> phonebook ;
  std::string name, phone_num, question ;

  for ( int i = 0 ; i < num ; i++ ) {

    std::cin >> name >> phone_num ;

    phonebook[name] = phone_num ;

  }

  while ( 1 ) {

    std::cin >> question ;

    if ( question == "QUIT" )
      break ;

    auto foundPerson = phonebook.find(question) ;

    if ( foundPerson != phonebook.end( ) )
      std::cout << foundPerson->second << std::endl ;
    else
      std::cout << "NOT FOUND" << std::endl ;

  }

  return 0 ;
  
}