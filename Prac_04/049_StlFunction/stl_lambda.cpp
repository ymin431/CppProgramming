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

  // ������ ��� ������ ��� ����� �����մϴ�. (std::sort)
  std::sort(inventory.begin(), inventory.end(), []( const Item& a, const Item& b ) { return a.price < b.price; } ) ;
  std::for_each(inventory.begin(), inventory.end(), [] ( const Item& a ) { std::cout << a.name << " " << a.price << " " << a.quantity << std::endl; } ) ;


  // Ư�� �̸��� ���� ǰ���� ã���ϴ�. (std::find_if)
  std::vector<Item>::iterator it = 
    std::find_if(inventory.begin(), inventory.end(), []( const Item& a ) { return a.name == "Grape"; } ) ;
  std::cout << "Item found: " << (*it).name << " " << (*it).price << " " << (*it).quantity << std::endl ;


  // Ư�� ���ݺ��� ��� ǰ���� ���� ����մϴ�. (std::count_if)
  int under_2 = std::count_if(inventory.begin(), inventory.end(), [] ( const Item& a ) { return a.price <= 2; } ) ;
  std::cout << "Number of expensive items: " << under_2 << std::endl ;


  // ��� 0�� ǰ���� ��Ͽ��� �����մϴ�. (std::remove_if)
  inventory.erase( std::remove_if(inventory.begin(), inventory.end(), [] ( const Item& a ) { return a.quantity == 0; } ), inventory.end() ) ;

  return 0;

}