#include "Logger.h"

int Logger::logLevel = 1 ;

void Logger::setLogLevel( int level ) {

  logLevel = level ;

}

void Logger::debug( const std::string& sentence, const std::string& tag ) {


  if ( logLevel <= LogLevel::DEBUG )
      std::cout << "[DEBUG][" << tag << "] " << sentence << std::endl ;

}

void Logger::info( const std::string& sentence, const std::string& tag ) {

  if ( logLevel <= LogLevel::INFO )
      std::cout << "[INFO][" << tag << "] " << sentence << std::endl ;

}


void Logger::warning( const std::string& sentence, const std::string& tag ) {
  if ( logLevel <= LogLevel::WARNING )
      std::cout << "[WARNING][" << tag << "] " << sentence << std::endl ;

}

void Logger::error( const std::string& sentence, const std::string& tag ) {

  if ( logLevel <= LogLevel::ERROR )
      std::cout << "[ERROR][" << tag << "] " << sentence << std::endl ;
      
}
