#include "Checkout.h"

#define DISCOUNT_20 20
#define DISCOUNT_50 50

int Checkout::calculateTotalPrice(std::vector<Item>::const_iterator begin, std::vector<Item>::const_iterator end) const {

    int sum = std::accumulate(begin, end, 0,
                              [](int sum, const Item& i){ return sum + (i.getPrice() * i.getQuantity()) ; }) ;
    return sum ;

}

void Checkout::setShippingAddress(const std::string &shippingAddress) {



}

void Checkout::setDiscountCode(DiscountCode discountCode) {



}