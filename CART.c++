#include "CART.hpp"
#include <iomanip>
#include "COLOR.h++"
#include "PRODUCT.hpp"
#include <set>
#include "UI.hpp"

CART* CART::instance =  NULL;

/**
 * @brief Function to get the instance of the CART class (singleton pattern).
 * @return Pointer to the CART instance.
 */
CART* CART::getinStance()
{
    if (instance == NULL)
    {
        instance = new CART();
        return instance;
    }
    else
    {
        return instance;
    }
}

/**
 * @brief Function to add a product item to the shopping cart.
 * @param item The PRODUCT object to be added to the cart.
 */
void CART::addToCart(PRODUCT item)
{
    CART *cart = CART::getinStance();
    cart->items.push_back(item);
    this->totalItems += 1;
    this->totalPrice += item.getPrice();
}

/**
 * @brief Function to clear the contents of the shopping cart.
 */
void CART::clearCart()
{
    CART *cart = CART::getinStance();
    cart->items.clear();
    cart->totalItems = 0;
    cart->totalPrice = 0;
}

/**
 * @brief Function to show the contents of the shopping cart using the UI class.
 */
void CART::showCart()
{
    UI *ui = UI::getUIInstace();
    ui->showCart();
}
