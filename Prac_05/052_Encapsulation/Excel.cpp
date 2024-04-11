#include "Excel.h"

Excel::Excel( std::vector<std::vector<Cell>> data ) : data(data) {} ;

double Excel::average( int fromRow, int fromCol, int toRow, int toCol ) const {

  double sum = 0 ;

  for ( int i = fromRow ; i <= toRow ; i++ ) {

    for ( int j = fromCol ; j <= toCol ; j++ ) {

      if ( data[i][j].getType() == INT ) 
        sum += data[i][j].getIntVal() ;

      else 
        sum += data[i][j].getDoubleVal() ;

    }

  }

  double avg = sum / 3 ;

  return avg ;

} ;