#include <iostream>
#include <vector>
#include <algorithm>

struct Item {

  int id ;
  std::string name ;
  int quantity ;
  int price ;

};

int main() {

  std::vector<Item*> item_lst ;

  int item_count = 0;

  Item *cart = nullptr;

  while (true) {

    int choice ;
    std::cin >> choice ;

    switch ( choice ) {

      // 1. Add item
      case 1: {
        cart = new Item;
        cart->id = item_count ;
        std::cout << "Enter item name: " ;
        std::cin >> cart->name ;
        std::cout << "Enter item quantity: " ;
        std::cin >> cart->quantity ;
        std::cout << "Enter item price: " ;
        std::cin >> cart->price ;
        item_lst.push_back(cart) ;
        std::cout << "\tItem " << item_count << " added successfully" << std::endl ;
        item_count++ ;
        // delete cart ;
        break ;
      }

      // 2. Delete item
      case 2: {
        std::cout << "Enter item ID: " ;
        int del_id ;
        std::cin >> del_id ;
        auto item_found = std::find_if(item_lst.begin(), item_lst.end(), [del_id] ( const Item* a ) { return a->id == del_id; }) ;
        if ( item_found != item_lst.end() ) {
          delete *item_found ;
          item_lst.erase(item_found) ;
          std::cout << "\tItem deleted successfully." << std::endl ;
          item_count-- ;
        }
        else
          std::cout << "\tItem not found" << std::endl ;
        break ;
      }

      // 3. View item details
      case 3: {
        std::cout << "Enter the item number: " ;
        int search ;
        std::cin >> search ;
        auto item_found = std::find_if(item_lst.begin(), item_lst.end(), [search] ( const Item* a ) { return a->id == search; }) ;
        if ( item_found != item_lst.end() ) {
          std::cout << "Item " << (*item_found)->id << ":" << std::endl ;
          std::cout << "\tName: " << (*item_found)->name << std::endl ;
          std::cout << "\tQuantity: " << (*item_found)->quantity << std::endl ;
          std::cout << "\tPrice: " << (*item_found)->price << std::endl ;
        }
        else 
          std::cout << "\tItem not found" << std::endl ;
        break ;
      }

      // 4. View total cost
      case 4: {
        int total = 0 ;
        for ( auto i : item_lst )
          total += i->price * i->quantity ;
        std::cout << "\tTotal cost: " << total << std::endl ;
        break ;
      }
      
      // 5. Quit
      case 5: {
        return 0;
      }

      default: {
        std::cout << "Invalid choice" << std::endl ;
        break ;
      }
        
    }

    std::cout << "1. Add item" << std::endl;

    std::cout << "2. Delete item" << std::endl;

    std::cout << "3. View item details" << std::endl;

    std::cout << "4. View total cost" << std::endl;

    std::cout << "5. Quit" << std::endl;

    std::cout << "Enter your choice: ";

  }

}