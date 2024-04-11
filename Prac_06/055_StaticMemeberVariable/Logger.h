#include <iostream>

enum LogLevel {
  DEBUG = 0,
  INFO = 1,
  WARNING = 2,
  ERROR = 3
} ;


class Logger {

  public:

    static void setLogLevel( int level ) ;
    static void debug( const std::string& sentence, const std::string& tag ) ;
    static void info( const std::string& sentence, const std::string& tag ) ;
    static void warning( const std::string& sentence, const std::string& tag ) ;
    static void error( const std::string& sentence, const std::string& tag ) ;


  private:
    static int logLevel ;

} ;