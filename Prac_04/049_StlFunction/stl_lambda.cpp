#include <iostream>
#include <vector>
#include <algorithm>

struct Item {

  std::string name;

  double price;

  int quantity;

} ;

bool cmp( const Item& a, const Item& b ) {

  if ( a.price * a.quantity < b.price * b.quantity ) return true ;
  // else if ( a.price * a.quantity == b.price * b.quantity ) 

  return false ;

}

int main() {

  std::vector<Item> inventory = {

    {"Apple", 0.99, 10},

    {"Banana", 0.59, 20},

    {"Cherry", 1.49, 5},

    {"Dates", 2.99, 2},

    {"Elderberry", 3.99, 0},

    {"Fig", 2.49, 15},

    {"Grape", 0.79, 25},

    {"Honeydew", 1.29, 8},

    {"Indian Gooseberry", 2.99, 0},

    {"Jackfruit", 4.99, 1}
  
  } ;

  // 가격이 비싼 순서로 재고 목록을 정렬합니다. (std::sort)
  std::sort(inventory.begin(), inventory.end(), []( const Item& a, const Item& b ) { return a.price < b.price; } ) ;
  std::for_each(inventory.begin(), inventory.end(), [] ( const Item& a ) { std::cout << a.name << " " << a.price << " " << a.quantity << std::endl; } ) ;


  // 특정 이름을 가진 품목을 찾습니다. (std::find_if)
  std::vector<Item>::iterator it = 
    std::find_if(inventory.begin(), inventory.end(), []( const Item& a ) { return a.name == "Grape"; } ) ;
  std::cout << "Item found: " << (*it).name << " " << (*it).price << " " << (*it).quantity << std::endl ;


  // 특정 가격보다 비싼 품목의 수를 계산합니다. (std::count_if)
  int under_2 = std::count_if(inventory.begin(), inventory.end(), [] ( const Item& a ) { return a.price <= 2; } ) ;
  std::cout << "Number of expensive items: " << under_2 << std::endl ;


  // 재고가 0인 품목을 목록에서 삭제합니다. (std::remove_if)
  inventory.erase( std::remove_if(inventory.begin(), inventory.end(), [] ( const Item& a ) { return a.quantity == 0; } ), inventory.end() ) ;

  return 0;

}