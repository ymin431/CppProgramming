#include "Checkout.cpp"

using const_iterator = std::vector<Item>::const_iterator;

class Cart {
public:
    Cart(Checkout* checkout) : checkout_(checkout) {}

    void addItem(const Item& item) ;
    void deleteItem(int id) ;
    int checkout() ;
    void viewItemDetails(int id, std::ostream& out) const ;

    const_iterator cbegin() const ;
    const_iterator cend() const ;

private:
    Checkout* checkout_;
    std::vector<Item> items;
};
