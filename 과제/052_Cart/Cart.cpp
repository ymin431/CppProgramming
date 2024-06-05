#include "Cart.h"

void Cart::addItem(const Item &item) {

    this->items.push_back(item) ;

}

void Cart::deleteItem(int id) {

    auto foundItem = std::find_if(this->cbegin(), this->cend(),
                                   [id](const Item& i){ return i.getId() == id ; }) ;
    if ( foundItem != this->cend() ) {
        this->items.erase(foundItem) ;
    }

}

int Cart::checkout() {

    int totalPrice = this->checkout_->calculateTotalPrice(this->cbegin(), this->cend()) ;
    return totalPrice ;

}

void Cart::viewItemDetails(int id, std::ostream &out) const {

    auto foundItem = std::find_if(this->cbegin(), this->cend(),
                                  [id] ( const Item& i ) { return i.getId() == id ; }) ;
    if ( foundItem != this->cend() ) {
        out << "Item " << (*foundItem).getId() << ":" << std::endl ;
        out << "\tName: " << (*foundItem).getName() << std::endl ;
        out << "\tQuantity: " << (*foundItem).getQuantity() << std::endl ;
        out << "\tPrice: " << (*foundItem).getPrice() << std::endl ;
    }
    else
        out << "\tItem not found" << std::endl ;

}

const_iterator Cart::cbegin() const {
    return this->items.begin() ;
}

const_iterator Cart::cend() const {
    return  this->items.end() ;
}