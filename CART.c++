#include <vector>
#include "PRODUCT.c++"
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
     CART::CART()
    {
    }
    
public:


    // delete the default copy constructor
    CART(const CART &obj) =  delete;

    static CART* getinStance();
    void addToCart(PRODUCT item);
    void clearCart();

};

CART* CART::instance =  NULL;

CART* CART::getinStance()
{
    {

        if (instance == NULL){
            instance =  new CART();
            return instance;
        }
        else
        {
            return instance;
        }
    }
}

void CART::addToCart(PRODUCT item)
{
    CART *cart = CART::getinStance();
    cart->items.push_back(item);
    this->totalItems +=1;
    this->totalPrice += item.getPrice();
}

void CART::clearCart()
{
    CART *cart = CART::getinStance();
   cart->items.clear();
   cart->totalItems = 0;
   cart->totalPrice = 0;
}