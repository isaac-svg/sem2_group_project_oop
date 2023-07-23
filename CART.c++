#include "CART.hpp"
#include <iomanip>
#include "COLOR.h++"
#include "PRODUCT.hpp"
#include <set>
#include "UI.hpp"

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
/**
 * @item: 
*/
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

UI *ui = UI::getUIInstace();
ui->showCart();


}

