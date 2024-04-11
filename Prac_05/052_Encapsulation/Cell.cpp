#include "Cell.h"

Cell::Cell( ) {} ;

Cell::Cell( std::string val ) : stringVal(val) { this->type = CELL_TYPE::STRING; } ;

Cell::Cell( int val ) : intVal(val) { this-> type = CELL_TYPE::INT; } ;

Cell::Cell( double val ) : doubleVal(val) { this->type = CELL_TYPE::DOUBLE; } ;

CELL_TYPE Cell::getType() const { return this->type; } ;

std::string Cell::getStringVal() const { return this->stringVal; } ;

int Cell::getIntVal() const { return this->intVal; } ;

double Cell::getDoubleVal() const { return this->doubleVal; } ;