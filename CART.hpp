#ifndef CART_H
#define CART_H
#include <vector>
#include "PRODUCT.hpp"
#include <stddef.h>
using namespace std;

// making CART a singleton class since we only want to instantiate cart one
class CART
{
private:
    int totalItems;
    // use the momey beuatifier
    double totalPrice;
    static CART* instance;
    vector<PRODUCT>items;
     CART()
    {
    }
    
public:


    // delete the default copy constructor
    CART(const CART &obj) =  delete;

    static CART* getinStance();
    void addToCart(PRODUCT item);
    void clearCart();

};

#endif