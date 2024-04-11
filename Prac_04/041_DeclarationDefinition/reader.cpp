extern std::vector<int> vec ;
extern int total ;

void read( ) {

  int len, num ;

  std::cin >> len ;

  for ( int i = 0 ; i < len ; i++ ) {

    std::cin >> num ;
    vec.push_back( num ) ;

  }

}