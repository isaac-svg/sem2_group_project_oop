#include "CART.hpp"

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

void CART::showCart(){
    CART *readyCart =  CART::getinStance();
   vector<PRODUCT>cartItems  = readyCart->items;

   for (auto &&itm : cartItems)
   {
    cout<< itm.getprice() << "\n";
    cout<< itm.getdesc() << "\n";
    cout<< itm.getname() << "\n";
    cout<< itm.getquantity() << "\n";

   }
   
}